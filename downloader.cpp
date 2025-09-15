#include "downloader.h"



Downloader::Downloader(const QUrl &url, const QString &outputPath, QListWidget *inProgressList,
                       QListWidget *historyList, QObject *parent)
    : QObject(parent), m_outputFile(outputPath), m_inProgressList(inProgressList), m_historyList(historyList) {

    QString fileName = outputPath.section('/', -1);
    m_progressWidget = new DownloadProgressWidget(fileName);


    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(m_progressWidget->sizeHint());
    m_inProgressList->insertItem(0, item);
    m_inProgressList->setItemWidget(item, m_progressWidget);

    QNetworkRequest request(url);
    QNetworkReply *reply = m_manager.get(request);

    connect(reply, &QNetworkReply::readyRead, this, [this, reply]() {
        if (!m_outputFile.isOpen()) {
            m_outputFile.open(QIODevice::WriteOnly);
        }
        m_outputFile.write(reply->readAll());
    });

    // connect(reply, &QNetworkReply::downloadProgress, m_progressWidget, &DownloadProgressWidget::updateProgress);
    connect(reply, &QNetworkReply::downloadProgress, this, [this](qint64 bytesReceived, qint64 bytesTotal) {
        m_totalBytes = bytesReceived;
        m_progressWidget->updateProgress(bytesReceived, bytesTotal);
    });

    connect(reply, &QNetworkReply::errorOccurred, this, [](QNetworkReply::NetworkError code) {
        qDebug() << "Download error:" << code;
    });

    connect(&m_manager, &QNetworkAccessManager::finished, this, &Downloader::onFinished);

    m_reply = reply;
    m_timer.start();
}

void Downloader::onFinished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    m_outputFile.close();
    m_reply->deleteLater();
    m_progressWidget->downloadFinished();

    // Remove widget from in-progress list
    for (int i = 0; i < m_inProgressList->count(); ++i) {
        if (m_inProgressList->itemWidget(m_inProgressList->item(i)) == m_progressWidget) {
            QListWidgetItem *item = m_inProgressList->takeItem(i);
            delete item;
            break;
        }
    }

    // Calculate download speed (KB/s)
    qint64 elapsedSecs = m_timer.elapsed() / 1000;
    if (elapsedSecs == 0) elapsedSecs = 1; // avoid divide-by-zero
    double speedKBps = m_totalBytes / 1024.0 / elapsedSecs;

    // Create entry for history
    QString fileName = m_outputFile.fileName().section('/', -1);
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm");
    QString historyEntry = QString("%1 | %2 KB/s | %3")
                               .arg(fileName)
                               .arg(QString::number(speedKBps, 'f', 2))
                               .arg(date);

    // Add to history list at the top
    if (m_historyList) {
        m_historyList->insertItem(0, historyEntry);
    }

    qDebug() << "Download finished.";
}
