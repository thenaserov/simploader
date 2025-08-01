#include "downloadprogressdialog.h"

DownloadProgressDialog::DownloadProgressDialog(QWidget *parent)
    : QDialog(parent), progressBar(new QProgressBar), label(new QLabel("Downloading...")) {
    setWindowTitle("Download Progress");
    progressBar->setRange(0, 100);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(progressBar);
    setLayout(layout);
    resize(300, 100);
}

void DownloadProgressDialog::updateProgress(qint64 received, qint64 total)
{
    if (total > 0) {
        int percent = static_cast<int>((100.0 * received) / total);
        progressBar->setValue(percent);
        label->setText(QString("Downloaded %1 of %2")
                           .arg(QLocale().formattedDataSize(received))
                           .arg(QLocale().formattedDataSize(total)));
    }
}

void DownloadProgressDialog::downloadFinished()
{
    label->setText("Download complete!");
    progressBar->setValue(100);
}
