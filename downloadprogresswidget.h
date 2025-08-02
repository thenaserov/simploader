// downloadprogresswidget.h
#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QLocale>

class DownloadProgressWidget : public QWidget {
    Q_OBJECT
public:
    explicit DownloadProgressWidget(const QString &fileName, QWidget *parent = nullptr);

public slots:
    void updateProgress(qint64 received, qint64 total);
    void downloadFinished();

private:
    QProgressBar *progressBar;
    QLabel *label;
};
