#ifndef ADDDOWNLOAD_H
#define ADDDOWNLOAD_H

#include <QWidget>

namespace Ui {
class AddDownload;
}

class AddDownload : public QWidget
{
    Q_OBJECT

public:
    explicit AddDownload(QWidget *parent = nullptr);
    ~AddDownload();

private:
    Ui::AddDownload *ui;
};

#endif // ADDDOWNLOAD_H
