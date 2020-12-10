#ifndef QVIDEOSURFACESTREAM_H
#define QVIDEOSURFACESTREAM_H

#include <QAbstractVideoSurface>
#include <QPixmap>
#include <QVideoSurfaceFormat>
#include <QtGui>
#include <QCameraViewfinder>
#include <QWidget>

class QVideoSurfaceStream : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit QVideoSurfaceStream(QObject *parent = nullptr);
    virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;
    virtual bool present(const QVideoFrame &frame);

    QPixmap qPixmapStream;

signals:
    void frameReady(QPixmap);

public slots:
};

#endif // QVIDEOSURFACESTREAM_H
