#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   this->setWindowTitle("simploader");
   loadDownloadHistory();
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
}


void MainWindow::on_pbAddDownload_clicked()
{
   AddDownload *dl_pop_up = new AddDownload(nullptr,ui->lwInProgress, ui->lwHistory);
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
