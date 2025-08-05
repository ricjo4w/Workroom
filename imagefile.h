#ifndef IMAGEFILE_H
#define IMAGEFILE_H

#include "collectionfile.h"
#include <QImage>

/**
 * @class ImageFile
 * @brief Represents a still grayscale image file in a collection.
 *
 * The ImageFile class is a concrete subclass of CollectionFile used to represent
 * static thermal or grayscale image data. It handles loading the image from disk
 * and provides access to the image buffer for rendering in the user interface.
 *
 * Supported formats can include standard image files (e.g., PNG, TIFF) or
 * custom thermal image formats converted to QImage.
 */
class ImageFile : public CollectionFile {
public:
    /**
     * @brief Constructs an ImageFile with the specified ID.
     * @param id A unique identifier for the file within the collection.
     */
    explicit ImageFile(const QString& id);

    /**
     * @brief Loads the image data from a file on disk.
     *
     * This method uses Qt's QImage loading capabilities to read the
     * image from disk and stores it internally.
     *
     * @param filePath The full path to the image file.
     */
    void load(const QString& filePath) override;

    /**
     * @brief Exports the image to the specified location.
     *
     * This method writes the internal QImage buffer to disk in PNG format.
     *
     * @param targetPath The output path where the image will be saved.
     */
    void exportTo(const QString& targetPath) const override;

    /**
     * @brief Retrieves a const reference to the loaded image.
     * @return The internal QImage representing the image data.
     */
    const QImage& image() const;

private:
    QImage m_image; ///< The internal image buffer loaded from disk.
};


#endif // IMAGEFILE_H
