#include "adddownload.h"
#include "ui_adddownload.h"


AddDownload::AddDownload(QWidget *parent, QListWidget *prListWidget, QListWidget* lw, QString downloadDir)
   : QWidget(parent)
   , ui(new Ui::AddDownload)
   , m_listWidget(lw)
   , m_prDownload(prListWidget)
   , m_downloadDir(downloadDir)
{
   ui->setupUi(this);
   m_listWidget = lw;
   m_prDownload = prListWidget;
}

AddDownload::~AddDownload()
{
   delete ui;
}

void AddDownload::on_btnStartDownload_clicked()
{
    // 1. Get the URL from the QLineEdit and validate it
    QUrl url = ui->leDownloadLink->text();
    if (!url.isValid() || url.isEmpty()) {
        QMessageBox::warning(this, "Invalid URL", "Please enter a valid download link.");
        return;
    }

    // 2. Extract the file name (use a default name if necessary)
    QString fileName = url.fileName();
    if (fileName.isEmpty() || !fileName.contains('.')) {
        // Fallback or attempt to determine a reasonable filename
        fileName = "untitled_download_" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    }

    // 3. CRITICAL FIX: Use QDir to safely join the path and filename
    // QDir::filePath() ensures the correct path separator (e.g., /) is inserted.
    QString outputPath = QDir(m_downloadDir).filePath(fileName);

    // 4. Create and start the Downloader
    // Assuming Downloader constructor takes: (QUrl url, QString outputPath, ..., parent)
    Downloader *downloader = new Downloader(url, outputPath, m_prDownload, m_listWidget, this);

    // Note: If m_prDownload and m_listWidget are meant to be passed to a
    // QObject constructor, consider passing them as arguments or using signals/slots.

    this->close();
}

void AddDownload::on_btnCancel_clicked()
{
    this->close();
}

