/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *pDownloadHistory;
    QGridLayout *gridLayout_3;
    QWidget *wDownloadHistory;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QPushButton *pbClearAllHistory;
    QWidget *pSettings;
    QGridLayout *gridLayout_4;
    QWidget *wSettings;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QPushButton *pbSaveSettings;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *pDownloadList;
    QGridLayout *gridLayout_2;
    QWidget *wDownloadList;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QListWidget *listWidget_2;
    QPushButton *pbAddDownload;
    QPushButton *pbDownloadHistory;
    QPushButton *pbDownloadList;
    QPushButton *pbSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(694, 437);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        pDownloadHistory = new QWidget();
        pDownloadHistory->setObjectName("pDownloadHistory");
        gridLayout_3 = new QGridLayout(pDownloadHistory);
        gridLayout_3->setObjectName("gridLayout_3");
        wDownloadHistory = new QWidget(pDownloadHistory);
        wDownloadHistory->setObjectName("wDownloadHistory");
        verticalLayout_2 = new QVBoxLayout(wDownloadHistory);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(wDownloadHistory);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        listWidget = new QListWidget(wDownloadHistory);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);

        pbClearAllHistory = new QPushButton(wDownloadHistory);
        pbClearAllHistory->setObjectName("pbClearAllHistory");

        verticalLayout_2->addWidget(pbClearAllHistory);


        gridLayout_3->addWidget(wDownloadHistory, 0, 0, 1, 1);

        stackedWidget->addWidget(pDownloadHistory);
        pSettings = new QWidget();
        pSettings->setObjectName("pSettings");
        gridLayout_4 = new QGridLayout(pSettings);
        gridLayout_4->setObjectName("gridLayout_4");
        wSettings = new QWidget(pSettings);
        wSettings->setObjectName("wSettings");
        gridLayout_6 = new QGridLayout(wSettings);
        gridLayout_6->setObjectName("gridLayout_6");
        verticalSpacer = new QSpacerItem(20, 98, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(201, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 0, 1, 1);

        widget = new QWidget(wSettings);
        widget->setObjectName("widget");
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName("gridLayout_5");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout_5->addWidget(label_2, 1, 0, 1, 2);

        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName("spinBox_2");

        gridLayout_5->addWidget(spinBox_2, 1, 2, 1, 1);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");

        gridLayout_5->addWidget(spinBox, 0, 2, 1, 1);

        pbSaveSettings = new QPushButton(widget);
        pbSaveSettings->setObjectName("pbSaveSettings");

        gridLayout_5->addWidget(pbSaveSettings, 2, 0, 1, 3);


        gridLayout_6->addWidget(widget, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(201, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 97, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 2, 1, 1, 1);


        gridLayout_4->addWidget(wSettings, 0, 0, 1, 1);

        stackedWidget->addWidget(pSettings);
        pDownloadList = new QWidget();
        pDownloadList->setObjectName("pDownloadList");
        gridLayout_2 = new QGridLayout(pDownloadList);
        gridLayout_2->setObjectName("gridLayout_2");
        wDownloadList = new QWidget(pDownloadList);
        wDownloadList->setObjectName("wDownloadList");
        verticalLayout = new QVBoxLayout(wDownloadList);
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(wDownloadList);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        listWidget_2 = new QListWidget(wDownloadList);
        listWidget_2->setObjectName("listWidget_2");

        verticalLayout->addWidget(listWidget_2);

        pbAddDownload = new QPushButton(wDownloadList);
        pbAddDownload->setObjectName("pbAddDownload");

        verticalLayout->addWidget(pbAddDownload);


        gridLayout_2->addWidget(wDownloadList, 0, 0, 1, 1);

        stackedWidget->addWidget(pDownloadList);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 3);

        pbDownloadHistory = new QPushButton(centralwidget);
        pbDownloadHistory->setObjectName("pbDownloadHistory");

        gridLayout->addWidget(pbDownloadHistory, 0, 1, 1, 1);

        pbDownloadList = new QPushButton(centralwidget);
        pbDownloadList->setObjectName("pbDownloadList");

        gridLayout->addWidget(pbDownloadList, 0, 0, 1, 1);

        pbSettings = new QPushButton(centralwidget);
        pbSettings->setObjectName("pbSettings");

        gridLayout->addWidget(pbSettings, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "history", nullptr));
        pbClearAllHistory->setText(QCoreApplication::translate("MainWindow", "clear all -", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Threads count", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Max download count", nullptr));
        pbSaveSettings->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "list", nullptr));
        pbAddDownload->setText(QCoreApplication::translate("MainWindow", "Add +", nullptr));
        pbDownloadHistory->setText(QCoreApplication::translate("MainWindow", "Download history", nullptr));
        pbDownloadList->setText(QCoreApplication::translate("MainWindow", "Download list", nullptr));
        pbSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
