#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H

#include <QWidget>
#include <QCamera>
#include <QCameraInfo>

namespace Ui {
class WidgetMain;
}

class WidgetMain : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetMain(QWidget *parent = 0);
    ~WidgetMain();

    void listarCamaras();
    void crearCamara(QByteArray deviceName);
    void destruirCamara();
    void activarCamara(bool activar);

public slots:
    void slotFrameReady(QPixmap qPixmap);

private slots:
    void on_chbCamara_clicked(bool checked);

    void on_btnListarCamaras_clicked();

    void on_btnTakePhoto_clicked();

private:
    Ui::WidgetMain *ui;
};

#endif // WIDGETMAIN_H
