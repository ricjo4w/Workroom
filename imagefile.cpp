#include "imagefile.h"

#include <QFileInfo>
#include <QImageReader>
#include <QImageWriter>
#include <QDebug>

ImageFile::ImageFile(const QString& id)
    : CollectionFile(id, Type::Image)
{
}

void ImageFile::load(const QString& filePath) {
    QImageReader reader(filePath);
    reader.setAutoTransform(true);
    if (!reader.read(&m_image)) {
        qWarning() << "Failed to load image:" << filePath << "-" << reader.errorString();
        m_image = QImage();  // Clear image on failure
    }
}

void ImageFile::exportTo(const QString& targetPath) const {
    QImageWriter writer(targetPath, "PNG");
    if (!writer.write(m_image)) {
        qWarning() << "Failed to export image to:" << targetPath << "-" << writer.errorString();
    }
}

const QImage& ImageFile::image() const {
    return m_image;
}
