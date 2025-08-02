#ifndef ADDDOWNLOAD_H
#define ADDDOWNLOAD_H

#include <QWidget>
#include <QCoreApplication>
#include <QFile>
#include <QUrl>
#include <QDebug>
#include "downloader.h"

namespace Ui {
class AddDownload;
}

class AddDownload : public QWidget
{
    Q_OBJECT

public:
    explicit AddDownload(QWidget *parent = nullptr, QListWidget *prWidget = nullptr, QListWidget* lw = nullptr);
    ~AddDownload();
    QUrl url;

private slots:
    void on_btnStartDownload_clicked();

private:
    Ui::AddDownload *ui;
    QListWidget *m_listWidget = nullptr;
    QListWidget * m_prDownload = nullptr;
};

#endif // ADDDOWNLOAD_H
