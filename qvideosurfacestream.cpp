#include "qvideosurfacestream.h"

QVideoSurfaceStream::QVideoSurfaceStream(QObject *parent) : QAbstractVideoSurface(parent)
{
}

QList<QVideoFrame::PixelFormat> QVideoSurfaceStream::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleType) const
{
    Q_UNUSED(handleType);

    QList<QVideoFrame::PixelFormat> formats;
    formats << QVideoFrame::Format_ARGB32;
    formats << QVideoFrame::Format_ARGB32_Premultiplied;
    formats << QVideoFrame::Format_RGB32;
    formats << QVideoFrame::Format_RGB24;
    formats << QVideoFrame::Format_RGB565;
    formats << QVideoFrame::Format_RGB555;
    return formats;
}

bool QVideoSurfaceStream::present(const QVideoFrame &frame)
{
    QVideoFrame frameCopy(frame);

    frameCopy.map(QAbstractVideoBuffer::ReadOnly);
    QImage qImage(frameCopy.bits(), frameCopy.width(), frameCopy.height(), frameCopy.bytesPerLine(), QImage::Format_RGB32);
    frameCopy.unmap();

    qPixmapStream=QPixmap::fromImage(qImage);
    emit frameReady(qPixmapStream);

    return true;
}
