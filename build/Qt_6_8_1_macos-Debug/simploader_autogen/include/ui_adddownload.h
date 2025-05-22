/********************************************************************************
** Form generated from reading UI file 'adddownload.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDOWNLOAD_H
#define UI_ADDDOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDownload
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leDownloadLink;
    QPushButton *btnStartDownload;

    void setupUi(QWidget *AddDownload)
    {
        if (AddDownload->objectName().isEmpty())
            AddDownload->setObjectName("AddDownload");
        AddDownload->resize(342, 194);
        gridLayout = new QGridLayout(AddDownload);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(AddDownload);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leDownloadLink = new QLineEdit(AddDownload);
        leDownloadLink->setObjectName("leDownloadLink");

        gridLayout->addWidget(leDownloadLink, 0, 1, 1, 1);

        btnStartDownload = new QPushButton(AddDownload);
        btnStartDownload->setObjectName("btnStartDownload");

        gridLayout->addWidget(btnStartDownload, 1, 0, 1, 2);


        retranslateUi(AddDownload);

        QMetaObject::connectSlotsByName(AddDownload);
    } // setupUi

    void retranslateUi(QWidget *AddDownload)
    {
        AddDownload->setWindowTitle(QCoreApplication::translate("AddDownload", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddDownload", "Link: ", nullptr));
        btnStartDownload->setText(QCoreApplication::translate("AddDownload", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDownload: public Ui_AddDownload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDOWNLOAD_H
