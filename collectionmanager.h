#ifndef COLLECTIONMANAGER_H
#define COLLECTIONMANAGER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>
#include <memory>
#include "collection.h"
//#include "collectionfile.h"

/**
 * @class CollectionManager
 * @brief Manages loading, tracking, and access of all active collections and files.
 *
 * The CollectionManager class is responsible for maintaining all active collections
 * within the application. It provides APIs to load new collections, remove existing ones,
 * and perform fast lookups of files and collections by their unique IDs.
 *
 * The manager also emits signals to notify the UI or other subsystems when collections
 * are added or removed, enabling automatic updates and session synchronization.
 */
class CollectionManager : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Constructs a new CollectionManager instance.
     * @param parent The QObject parent, used for memory management and signal propagation.
     */
    explicit CollectionManager(QObject* parent = nullptr);

    /**
     * @brief Loads a collection from the specified path.
     *
     * Creates a new Collection object, loads all supported files from the directory,
     * registers the files for fast lookup, and emits the collectionAdded() signal.
     *
     * @param path The file system path to the collection folder or manifest.
     * @return A shared pointer to the loaded Collection.
     */
    std::shared_ptr<Collection> loadCollection(const QString& path);

    /**
     * @brief Removes a previously loaded collection by its name or ID.
     *
     * Deregisters all associated files and emits the collectionRemoved() signal.
     *
     * @param collectionId The name or identifier of the collection to remove.
     */
    void removeCollection(const QString& collectionId);

    /**
     * @brief Returns all currently loaded collections.
     *
     * @return A const reference to the internal list of collections.
     */
    const QList<std::shared_ptr<Collection>>& collections() const;

    /**
     * @brief Finds a collection by its identifier.
     *
     * Performs a linear search through all loaded collections by name or path.
     *
     * @param id The name or unique identifier of the collection.
     * @return A shared pointer to the matching Collection, or nullptr if not found.
     */
    std::shared_ptr<Collection> findCollectionById(const QString& id) const;

    /**
     * @brief Finds a file by its unique ID across all loaded collections.
     *
     * Uses an internal map for constant-time lookup.
     *
     * @param id The unique file ID to search for.
     * @return A shared pointer to the matching CollectionFile, or nullptr if not found.
     */
    std::shared_ptr<CollectionFile> findFileById(const QString& id) const;

signals:
    /**
     * @brief Emitted when a new collection is successfully loaded.
     * @param collection A shared pointer to the newly added collection.
     */
    void collectionAdded(std::shared_ptr<Collection> collection);

    /**
     * @brief Emitted when a collection is removed.
     * @param collectionId The identifier of the removed collection.
     */
    void collectionRemoved(const QString& collectionId);

private:
    QList<std::shared_ptr<Collection>> m_collections; ///< List of all loaded collections.
    QMap<QString, std::shared_ptr<CollectionFile>> m_fileLookup; ///< Maps file ID to CollectionFile.
};


#endif // COLLECTIONMANAGER_H
