#include "downloadprogresswidget.h"

DownloadProgressWidget::DownloadProgressWidget(const QString &fileName, QWidget *parent)
    : QWidget(parent), progressBar(new QProgressBar), label(new QLabel) {
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel(fileName)); // File name label
    layout->addWidget(progressBar);
    layout->addWidget(label);
    setLayout(layout);
    progressBar->setRange(0, 100);
    label->setText("Starting download...");
}

void DownloadProgressWidget::updateProgress(qint64 received, qint64 total)
{
    if (total > 0) {
        int percent = static_cast<int>((100.0 * received) / total);
        progressBar->setValue(percent);
        label->setText(QString("Downloaded %1 of %2")
                           .arg(QLocale().formattedDataSize(received))
                           .arg(QLocale().formattedDataSize(total)));
    }
}

void DownloadProgressWidget::downloadFinished()
{
    label->setText("Download complete!");
    progressBar->setValue(100);
}
