#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include "downloadhistoryentry.h"
#include "adddownload.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();

private slots:
void on_pbDownloadList_clicked();

void on_pbDownloadHistory_clicked();

void on_pbSettings_clicked();

void on_pbSaveSettings_clicked();

void on_pbAddDownload_clicked();

void on_pbSaveTo_clicked();

private:
Ui::MainWindow *ui;
    void saveDownloadHistory();
void loadDownloadHistory();
    void initIcons();
};
#endif // MAINWINDOW_H
