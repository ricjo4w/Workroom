#ifndef COLLECTION_H
#define COLLECTION_H

#include <QString>
#include <QList>
#include <memory>
#include "collectionfile.h"

/**
 * @class Collection
 * @brief Represents a logical group of files loaded as a data collection.
 *
 * The Collection class encapsulates a group of related files loaded from a
 * specified directory or manifest. Each file is represented by a subclass of
 * CollectionFile and can be accessed individually. Collections are used to
 * manage context and grouping for analysis or processing workflows.
 */
class Collection {
public:
    /**
     * @brief Constructs a new Collection from a specified path.
     *
     * Initializes a new Collection instance by parsing files located at the
     * given file system path. Files are wrapped in appropriate CollectionFile
     * subclasses and stored internally.
     *
     * @param path The directory or manifest path where the collection is located.
     */
    explicit Collection(const QString& path);

    /**
     * @brief Returns the name or display label of the collection.
     *
     * Typically derived from the collection directory's base name.
     *
     * @return A QString representing the name of the collection.
     */
    QString name() const;

    /**
     * @brief Returns the original path used to load this collection.
     *
     * Useful for reloading the same collection or saving session state.
     *
     * @return A QString with the absolute or relative collection path.
     */
    QString path() const;

    /**
     * @brief Returns all files contained within the collection.
     *
     * @return A QList of shared pointers to CollectionFile objects.
     */
    const QList<std::shared_ptr<CollectionFile>>& files() const;

    /**
     * @brief Finds a file in the collection by its unique ID.
     *
     * Performs a linear search and returns the file if found, or nullptr if not.
     *
     * @param id The unique file ID to search for.
     * @return A shared pointer to the matching CollectionFile, or nullptr.
     */
    std::shared_ptr<CollectionFile> findById(const QString& id) const;

private:
    QString m_path;  ///< The file system path used to load the collection.
    QString m_name;  ///< Display name of the collection.
    QList<std::shared_ptr<CollectionFile>> m_files; ///< List of all file objects in the collection.

    /**
     * @brief Loads all supported files from the given path.
     *
     * Internal helper function that populates the m_files list.
     */
    void loadFiles();
};


#endif // COLLECTION_H
