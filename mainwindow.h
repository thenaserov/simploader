#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
