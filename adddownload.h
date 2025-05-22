#ifndef ADDDOWNLOAD_H
#define ADDDOWNLOAD_H

#include <QWidget>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>

class Downloader : public QObject {
    Q_OBJECT

public:
    Downloader(const QUrl &url, const QString &outputPath, QObject *parent = nullptr)
        : QObject(parent), m_outputFile(outputPath) {
        connect(&m_manager, &QNetworkAccessManager::finished, this, &Downloader::onFinished);

        QNetworkRequest request(url);
        QNetworkReply *reply = m_manager.get(request);

        connect(reply, &QNetworkReply::readyRead, this, [this, reply]() {
            if (!m_outputFile.isOpen()) {
                m_outputFile.open(QIODevice::WriteOnly);
            }
            m_outputFile.write(reply->readAll());
        });

        connect(reply, &QNetworkReply::downloadProgress, this, [](qint64 bytesReceived, qint64 bytesTotal) {
            qDebug() << "Download Progress:" << bytesReceived << "/" << bytesTotal;
        });

        connect(reply, &QNetworkReply::errorOccurred, this, [](QNetworkReply::NetworkError code) {
            qDebug() << "Download error:" << code;
        });
    }

private slots:
    void onFinished(QNetworkReply *reply) {
        m_outputFile.close();
        reply->deleteLater();
        qDebug() << "Download finished.";
        QCoreApplication::quit();
    }

private:
    QNetworkAccessManager m_manager;
    QFile m_outputFile;
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QUrl url("https://example.com/file.zip");              // Replace with your file URL
    QString outputPath = "downloaded_file.zip";            // Local path to save file

    Downloader downloader(url, outputPath);

    return app.exec();
}

#include "main.moc"


namespace Ui {
class AddDownload;
}

class AddDownload : public QWidget
{
Q_OBJECT

public:
explicit AddDownload(QWidget *parent = nullptr);
~AddDownload();
QString link;

private slots:
void on_btnStartDownload_clicked();

private:
Ui::AddDownload *ui;
};

#endif // ADDDOWNLOAD_H
