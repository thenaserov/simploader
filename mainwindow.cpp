#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("simploader");
}

MainWindow::~MainWindow()
{
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

