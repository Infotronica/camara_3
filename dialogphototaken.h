#ifndef DIALOGPHOTOTAKEN_H
#define DIALOGPHOTOTAKEN_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class DialogPhotoTaken;
}

class DialogPhotoTaken : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPhotoTaken(QWidget *parent = 0);
    ~DialogPhotoTaken();

public slots:
    void closeEvent(QCloseEvent *event);

public:
    void setPixmap(QPixmap qPixmap);
    void setMessage(QString qString);

private:
    Ui::DialogPhotoTaken *ui;
};

extern DialogPhotoTaken *dialogPhotoTaken;

#endif // DIALOGPHOTOTAKEN_H
