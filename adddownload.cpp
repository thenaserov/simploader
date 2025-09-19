#include "adddownload.h"
#include "ui_adddownload.h"


AddDownload::AddDownload(QWidget *parent, QListWidget *prListWidget, QListWidget* lw)
   : QWidget(parent)
   , ui(new Ui::AddDownload)
   , m_listWidget(lw)
   , m_prDownload(prListWidget)
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
    QString outputPath = "/Users/thenaserov/Downloads/" + url.fileName();
    Downloader *downloader = new Downloader(url, outputPath, m_prDownload, m_listWidget, this);
    this->close();
}
