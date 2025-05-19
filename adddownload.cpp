#include "adddownload.h"
#include "ui_adddownload.h"

AddDownload::AddDownload(QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::AddDownload)
{
   ui->setupUi(this);
}

AddDownload::~AddDownload()
{
   delete ui;
}


void AddDownload::on_btnStartDownload_clicked()
{
   link = ui->leDownloadLink->text();
}
