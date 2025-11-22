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
    url = ui->leDownloadLink->text();
    QString outputPath = m_downloadDir + url.fileName();
    Downloader *downloader = new Downloader(url, outputPath, m_prDownload, m_listWidget, this);
    this->close();
}

void AddDownload::on_btnCancel_clicked()
{
    this->close();
}

