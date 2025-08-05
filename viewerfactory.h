#ifndef VIEWERFACTORY_H
#define VIEWERFACTORY_H

#include <QWidget>
#include <memory>

class CollectionFile;

/**
 * @class ViewerFactory
 * @brief Factory for creating viewer widgets based on file type.
 *
 * The ViewerFactory is responsible for generating the appropriate QWidget-based
 * viewer for a given CollectionFile. This allows the UI to display or interact with
 * different file types (images, tables, videos, etc.) through a consistent interface.
 *
 * The factory uses the file's type information to instantiate the correct viewer
 * implementation. Each viewer is expected to inherit from QWidget and accept
 * a shared pointer to its corresponding CollectionFile-derived model.
 */
class ViewerFactory {
public:
    /**
     * @brief Creates a viewer widget for the given file.
     *
     * Based on the type of the CollectionFile, the factory will instantiate
     * and return a QWidget subclass capable of displaying or editing the file.
     *
     * @param file A shared pointer to the CollectionFile to be viewed.
     * @param parent Optional QWidget parent for ownership and layout purposes.
     * @return A new QWidget pointer for the viewer, or nullptr if unsupported.
     */
    static QWidget* createViewer(std::shared_ptr<CollectionFile> file, QWidget* parent = nullptr);
};

#endif // VIEWERFACTORY_H
