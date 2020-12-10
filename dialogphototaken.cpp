#include "dialogphototaken.h"
#include "ui_dialogphototaken.h"

DialogPhotoTaken *dialogPhotoTaken;

DialogPhotoTaken::DialogPhotoTaken(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPhotoTaken)
{
    ui->setupUi(this);
}

DialogPhotoTaken::~DialogPhotoTaken()
{
    delete ui;
    dialogPhotoTaken=nullptr;
}

void DialogPhotoTaken::closeEvent(QCloseEvent *event)
{
    delete dialogPhotoTaken;
    event->setAccepted(true);
}

void DialogPhotoTaken::setPixmap(QPixmap qPixmap)
{
    ui->labelPixmap->setPixmap(qPixmap);
}

void DialogPhotoTaken::setMessage(QString qString)
{
    ui->labelPixmap->setText(qString);
}
