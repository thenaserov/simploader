#pragma once
#include "downloadprogresswidget.h"
#include <QElapsedTimer>
#include <QFile>
#include <QListWidgetItem>
#include <QNetworkReply>
#include <QNetworkRequest>

class Downloader : public QObject {
    Q_OBJECT

public:
    Downloader(const QUrl &url, const QString &outputPath, QListWidget *inProgressList, QListWidget *historyList, QObject *parent = nullptr);

private slots:

    void onFinished(QNetworkReply *reply);



private:
    QNetworkAccessManager m_manager;
    QNetworkReply *m_reply;
    QFile m_outputFile;
    QListWidget *m_inProgressList;
    QListWidget *m_historyList;
    DownloadProgressWidget *m_progressWidget;
    QElapsedTimer m_timer;
    qint64 m_totalBytes = 0;
};
