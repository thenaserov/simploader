#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   this->setWindowTitle("simploader");
   loadDownloadHistory();
   initIcons();

   ui->label->hide();
   ui->label_2->hide();
   ui->spinBox->hide();
   ui->spinBox_2->hide();
   loadSettings();
   ui->pbSettings->hide();

   m_fileDialog = new QFileDialog(this);
   m_fileDialog->setFileMode(QFileDialog::Directory); // Select a directory
   m_fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
   // CRITICAL: Connect the non-static signal
   connect(m_fileDialog, &QFileDialog::directoryEntered, this, &MainWindow::onDirectorySelected);
   // Note: The `QFileDialog::getExistingDirectory` function is a static convenience method
   // that uses a *blocking* execution. The modern, non-blocking usage
   // connects to the signals and then calls `open()`.
}

MainWindow::~MainWindow()
{
   saveDownloadHistory();
   delete ui;
}

void MainWindow::on_pbDownloadList_clicked()
{
   this->setWindowTitle("Download List");
   ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pbDownloadHistory_clicked()
{
   this->setWindowTitle("Download History");
   ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pbSettings_clicked()
{
   this->setWindowTitle("Settings");
   ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pbSaveSettings_clicked()
{
    QString dir = ui->lblDownloadDir->text();

    QJsonObject obj;
    obj["download_dir"] = dir;

    QJsonDocument doc(obj);

    QFile file("settings.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}


void MainWindow::on_pbAddDownload_clicked()
{
   AddDownload *dl_pop_up = new AddDownload(nullptr,ui->lwInProgress, ui->lwHistory, /*downloadPath*/"/storage/emulated/0/Download/");
   dl_pop_up->show();
}

void MainWindow::saveDownloadHistory()
{
    QJsonArray array;

    for (int i = 0; i < ui->lwHistory->count(); ++i) {
        QString text = ui->lwHistory->item(i)->text();
        QStringList parts = text.split(" | ");
        if (parts.size() != 3) continue;

        DownloadHistoryEntry entry;
        entry.fileName = parts[0];
        entry.speedKBps = parts[1].remove(" KB/s").toDouble();
        entry.date = parts[2];

        array.append(entry.toJson());
    }

    QFile file("download_history.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(array).toJson());
        file.close();
    }
}

void MainWindow::loadDownloadHistory()
{
    QFile file("download_history.json");
    if (!file.open(QIODevice::ReadOnly))
        return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray array = doc.array();
    for (const QJsonValue &val : array) {
        DownloadHistoryEntry entry = DownloadHistoryEntry::fromJson(val.toObject());
        ui->lwHistory->addItem(entry.toDisplayString());
    }
}

void MainWindow::initIcons()
{
    // Add Download btn
    QPixmap pmAdd = QPixmap(":/resources/add.png");
    ui->pbAddDownload->setIcon(pmAdd);
    // Save Settings btn
    QPixmap pmSave = QPixmap(":/resources/save.png");
    ui->pbSaveSettings->setIcon(pmSave);
    // Clear All Histiry btn
    QPixmap pmClear = QPixmap(":/resources/clear.png");
    ui->pbClearAllHistory->setIcon(pmClear);
}

void MainWindow::loadSettings()
{
    QFile file("settings.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isObject()) {
            QJsonObject obj = doc.object();

            if (obj.contains("download_dir")) {
                QString dir = obj["download_dir"].toString();
                ui->lblDownloadDir->setText(dir);
            }
        }
    }
}

#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>

void MainWindow::on_pbSaveTo_clicked()
{
    // Use the non-static QFileDialog instance
    QFileDialog *fileDialog = new QFileDialog(this);

    // Set options for directory selection
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog->setOption(QFileDialog::ShowDirsOnly);

    // IMPORTANT: Let Android use its native picker (the source of the content:// URI)
    fileDialog->setOption(QFileDialog::DontUseNativeDialog, false);

    // Set the initial path to the system's standard Downloads folder
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    fileDialog->setDirectory(initialPath);

    // Use the accepted() signal for the final user selection
    connect(fileDialog, &QFileDialog::accepted, [fileDialog, this]() {
        QStringList selected = fileDialog->selectedFiles();
        if (!selected.isEmpty()) {
            // Pass the selected URI/path to the processing slot
            this->onDirectorySelected(selected.first());
        }
        fileDialog->deleteLater();
    });

    fileDialog->open();
}

void MainWindow::onDirectorySelected(const QString &path)
{
    qDebug() << "Native Picker Result Path (URI/Path):" << path;

    QString finalWritablePath;

    // 1. Determine the guaranteed writable path
    QString standardDownloadRoot = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);

    if (standardDownloadRoot.isEmpty()) {
        QMessageBox::critical(this, "Error", "Cannot determine a public writable Downloads folder.");
        return;
    }

    // 2. Create a dedicated subdirectory for your app (Best Practice)
    QDir dir(standardDownloadRoot);
    QString appSubDirName = "SimpLoader_Downloads";
    if (dir.mkpath(appSubDirName)) {
        finalWritablePath = dir.filePath(appSubDirName);
    } else {
        // Fallback to the root if we can't create a subdirectory
        finalWritablePath = standardDownloadRoot;
    }

    // 3. Set the downloadPath variable
    // We ignore the non-writable URI returned by the native selector
    // and use the guaranteed writable path instead.
    downloadPath = finalWritablePath;

    // Update the UI label with the final, WORKING path
    ui->lblDownloadDir->setText(downloadPath);

    qDebug() << "Final Download Path Stored:" << downloadPath;

    // Optional: Notify the user of the path adjustment
    QMessageBox::information(this, "Path Set (Hybrid Fix)",
                             "Download directory successfully set to:\n" + downloadPath +
                                 "\n(Uses system Downloads folder to guarantee file saving)."
                             );
}

void MainWindow::on_pbClearAllHistory_clicked()
{
    ui->lwHistory->clear();
    QFile file("download_history.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.resize(0);
        file.close();
    }
}
