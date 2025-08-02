// downloadprogressdialog.h
#pragma once

#include <QDialog>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QLocale>

class DownloadProgressDialog : public QDialog {
    Q_OBJECT
public:
    DownloadProgressDialog(QWidget *parent = nullptr);

public slots:
    void updateProgress(qint64 received, qint64 total);
    void downloadFinished();

private:
    QProgressBar *progressBar;
    QLabel *label;
};
