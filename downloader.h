// downloader.h
#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QListWidget>
#include "downloadprogressdialog.h"


class Downloader : public QObject {
    Q_OBJECT

public:
    Downloader(const QUrl &url, const QString &outputPath, QWidget *parentWidget = nullptr, QListWidget *historyList = nullptr)
        : QObject(parentWidget), m_outputFile(outputPath), m_historyList(historyList), dialog(new DownloadProgressDialog(parentWidget)) {

        dialog->show();

        connect(&m_manager, &QNetworkAccessManager::finished, this, &Downloader::onFinished);

        QNetworkRequest request(url);
        QNetworkReply *reply = m_manager.get(request);

        connect(reply, &QNetworkReply::readyRead, this, [this, reply]() {
            if (!m_outputFile.isOpen()) {
                m_outputFile.open(QIODevice::WriteOnly);
            }
            m_outputFile.write(reply->readAll());
        });

        connect(reply, &QNetworkReply::downloadProgress, dialog, &DownloadProgressDialog::updateProgress);

        connect(reply, &QNetworkReply::errorOccurred, this, [](QNetworkReply::NetworkError code) {
            qDebug() << "Download error:" << code;
        });

        connect(reply, &QNetworkReply::finished, dialog, &DownloadProgressDialog::downloadFinished);
    }

private slots:

    void onFinished(QNetworkReply *reply) {
        m_outputFile.close();
        reply->deleteLater();
        dialog->downloadFinished();

        if (m_historyList) {
            m_historyList->addItem(m_outputFile.fileName());
        }

        qDebug() << "Download finished.";
    }

private:
    QNetworkAccessManager m_manager;
    QFile m_outputFile;
    DownloadProgressDialog *dialog;
    QListWidget *m_historyList = nullptr;

};
