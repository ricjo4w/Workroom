#include "viewerfactory.h"
#include "collectionfile.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QTextEdit>

/**
 * Dummy viewer for image files.
 */
class ImageViewer : public QWidget {
public:
    explicit ImageViewer(std::shared_ptr<CollectionFile> file, QWidget* parent = nullptr)
        : QWidget(parent) {
        auto* layout = new QVBoxLayout(this);
        layout->addWidget(new QLabel("Image Viewer for: " + file->id(), this));
        setLayout(layout);
    }
};

/**
 * Dummy viewer for table files.
 */
class TableViewer : public QWidget {
public:
    explicit TableViewer(std::shared_ptr<CollectionFile> file, QWidget* parent = nullptr)
        : QWidget(parent) {
        auto* layout = new QVBoxLayout(this);
        layout->addWidget(new QLabel("Table Viewer for: " + file->id(), this));
        setLayout(layout);
    }
};

/**
 * Dummy viewer for PDF files.
 */
class PDFViewer : public QWidget {
public:
    explicit PDFViewer(std::shared_ptr<CollectionFile> file, QWidget* parent = nullptr)
        : QWidget(parent) {
        auto* layout = new QVBoxLayout(this);
        layout->addWidget(new QLabel("PDF Viewer for: " + file->id(), this));
        setLayout(layout);
    }
};

/**
 * Dummy viewer for video files.
 */
class VideoViewer : public QWidget {
public:
    explicit VideoViewer(std::shared_ptr<CollectionFile> file, QWidget* parent = nullptr)
        : QWidget(parent) {
        auto* layout = new QVBoxLayout(this);
        layout->addWidget(new QLabel("Video Viewer for: " + file->id(), this));
        setLayout(layout);
    }
};

QWidget* ViewerFactory::createViewer(std::shared_ptr<CollectionFile> file, QWidget* parent) {
    switch (file->type()) {
    case CollectionFile::Type::Image:
        return new ImageViewer(file, parent);
    case CollectionFile::Type::Table:
        return new TableViewer(file, parent);
    case CollectionFile::Type::PDF:
        return new PDFViewer(file, parent);
    case CollectionFile::Type::Video:
        return new VideoViewer(file, parent);
    case CollectionFile::Type::Unknown:
    default:
        return new QLabel("Unsupported file type: " + file->id(), parent);
    }
}
