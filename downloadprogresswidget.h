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
    explicit DownloadProgressWidget(const QString &fileName, QWidget *parent = nullptr)
        : QWidget(parent), progressBar(new QProgressBar), label(new QLabel) {
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(new QLabel(fileName)); // File name label
        layout->addWidget(progressBar);
        layout->addWidget(label);
        setLayout(layout);
        progressBar->setRange(0, 100);
        label->setText("Starting download...");
    }

public slots:
    void updateProgress(qint64 received, qint64 total) {
        if (total > 0) {
            int percent = static_cast<int>((100.0 * received) / total);
            progressBar->setValue(percent);
            label->setText(QString("Downloaded %1 of %2")
                               .arg(QLocale().formattedDataSize(received))
                               .arg(QLocale().formattedDataSize(total)));
        }
    }

    void downloadFinished() {
        label->setText("Download complete!");
        progressBar->setValue(100);
    }

private:
    QProgressBar *progressBar;
    QLabel *label;
};
