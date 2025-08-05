#ifndef COLLECTIONFILE_H
#define COLLECTIONFILE_H

#include <QString>
#include <QObject>

/**
 * @class CollectionFile
 * @brief Abstract base class for files within a data collection.
 *
 * CollectionFile defines a polymorphic interface for handling various file types
 * (such as images, videos, tables, and documents) in a data collection. It manages
 * core metadata like file ID and type, and declares virtual functions for loading
 * and exporting file contents. This allows different file types to be treated
 * uniformly throughout the application.
 */
class CollectionFile : public QObject {
    Q_OBJECT

public:
    /**
     * @enum Type
     * @brief Enumeration of supported file types.
     *
     * Defines the logical type of a file in a collection, which determines how it
     * is processed or displayed.
     */
    enum class Type {
        Image,   /**< A still image or static raster file. */
        Video,   /**< A temporal image sequence or infrared video. */
        Table,   /**< Structured tabular data (e.g. CSV, Excel). */
        PDF,     /**< Portable Document Format file. */
        Unknown  /**< An unrecognized or unsupported file type. */
    };

    /**
     * @brief Constructs a CollectionFile with a given ID and type.
     *
     * @param id A unique identifier for the file within the collection.
     * @param type The logical file type (image, video, etc.).
     */
    CollectionFile(QString id, Type type);

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    virtual ~CollectionFile();

    /**
     * @brief Retrieves the unique identifier for this file.
     *
     * @return A QString containing the file's ID.
     */
    QString id() const;

    /**
     * @brief Returns the logical type of this file.
     *
     * @return A value from the Type enum representing the file type.
     */
    Type type() const;

    /**
     * @brief Checks whether the file is currently open in the user interface.
     *
     * This flag is used to track viewer state across application sessions.
     *
     * @return True if the file is currently open, false otherwise.
     */
    bool isOpen() const;

    /**
     * @brief Sets whether the file is currently open in the user interface.
     *
     * @param open True to mark the file as open, false to mark it as closed.
     */
    void setIsOpen(bool open);

    /**
     * @brief Loads the contents of the file from disk.
     *
     * This pure virtual function must be implemented by subclasses
     * to parse and load the file from its on-disk location.
     *
     * @param filePath The full filesystem path to the file.
     */
    virtual void load(const QString& filePath) = 0;

    /**
     * @brief Exports the current state of the file to a new path.
     *
     * Subclasses implement this function to serialize or export their data.
     *
     * @param targetPath Destination path for the exported file.
     */
    virtual void exportTo(const QString& targetPath) const = 0;

protected:
    QString m_id;       ///< Unique file identifier.
    Type m_type;        ///< File type as defined by the Type enum.
    bool m_isOpen;      ///< Flag indicating if the file is currently open.
};


#endif // COLLECTIONFILE_H
