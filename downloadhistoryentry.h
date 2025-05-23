    #pragma once
#include <QString>
#include <QJsonObject>

struct DownloadHistoryEntry {
    QString fileName;
    double speedKBps;
    QString date;

    QJsonObject toJson() const {
        QJsonObject obj;
        obj["fileName"] = fileName;
        obj["speedKBps"] = speedKBps;
        obj["date"] = date;
        return obj;
    }

    static DownloadHistoryEntry fromJson(const QJsonObject &obj) {
        DownloadHistoryEntry entry;
        entry.fileName = obj["fileName"].toString();
        entry.speedKBps = obj["speedKBps"].toDouble();
        entry.date = obj["date"].toString();
        return entry;
    }

    QString toDisplayString() const {
        return QString("%1 | %2 KB/s | %3")
        .arg(fileName)
            .arg(QString::number(speedKBps, 'f', 2))
            .arg(date);
    }
};
