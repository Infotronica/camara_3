#include "widgetmain.h"
#include "ui_widgetmain.h"
#include "dialogphototaken.h"
#include "qvideosurfacestream.h"

QCamera *qCamera;
QVideoSurfaceStream *qVideoSurfaceStream;

WidgetMain::WidgetMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetMain)
{
    ui->setupUi(this);

    dialogPhotoTaken=nullptr;
    qCamera=nullptr;
    listarCamaras();
}

WidgetMain::~WidgetMain()
{
    activarCamara(false);
    delete ui;
}

void WidgetMain::listarCamaras()
{
    ui->cbxCamaras->clear();
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras)
    {
        ui->cbxCamaras->addItem(cameraInfo.description(), cameraInfo.deviceName());
    }
}

void WidgetMain::crearCamara(QByteArray deviceName)
{
    destruirCamara();
    qCamera = new QCamera(deviceName,this);
    qVideoSurfaceStream = new QVideoSurfaceStream(this);
    qCamera->setViewfinder(qVideoSurfaceStream);
    qCamera->setCaptureMode(QCamera::CaptureStillImage);
}

void WidgetMain::destruirCamara()
{
    QPixmap qPixmap;

    ui->labelVisor1->setPixmap(qPixmap);
    ui->labelVisor1->update();
    ui->labelVisor2->setPixmap(qPixmap);
    ui->labelVisor2->update();
    delete qVideoSurfaceStream;
    delete qCamera;
    qVideoSurfaceStream=nullptr;
    qCamera=nullptr;
}

void WidgetMain::activarCamara(bool activar)
{
    QByteArray deviceName;

    if (activar)
    {
        deviceName=ui->cbxCamaras->currentData().toByteArray();
        crearCamara(deviceName);
        QObject::connect(qVideoSurfaceStream, &QVideoSurfaceStream::frameReady, this, &WidgetMain::slotFrameReady);
        qCamera->start();
    }
    else
    {
        if (qCamera)
        {
            qCamera->stop();
        }
        QObject::disconnect(qVideoSurfaceStream, &QVideoSurfaceStream::frameReady, this, &WidgetMain::slotFrameReady);
        destruirCamara();
    }
}

void WidgetMain::slotFrameReady(QPixmap qPixmap)
{
    ui->labelVisor1->setPixmap(qPixmap);
    ui->labelVisor1->update();
    ui->labelVisor2->setPixmap(qPixmap);
    ui->labelVisor2->update();
}

void WidgetMain::on_chbCamara_clicked(bool checked)
{
    activarCamara(checked);
}

void WidgetMain::on_btnListarCamaras_clicked()
{
    listarCamaras();
}

void WidgetMain::on_btnTakePhoto_clicked()
{
    QPixmap qPixmap;

    if (dialogPhotoTaken==nullptr)
    {
        dialogPhotoTaken = new DialogPhotoTaken(this);
    }

    if (ui->labelVisor1->pixmap()!=nullptr)
    {
        qPixmap=ui->labelVisor1->pixmap()->copy();
        dialogPhotoTaken->setPixmap(qPixmap);
    }
    else
    {
        dialogPhotoTaken->setMessage("No hay imagen");
    }
    dialogPhotoTaken->show();
}
