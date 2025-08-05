#include "collectionmanager.h"

CollectionManager::CollectionManager(QObject* parent)
    : QObject(parent)
{}

std::shared_ptr<Collection> CollectionManager::loadCollection(const QString& path) {
    auto collection = std::make_shared<Collection>(path);
    m_collections.append(collection);

    for (const auto& file : collection->files()) {
        m_fileLookup.insert(file->id(), file);
    }

    emit collectionAdded(collection);
    return collection;
}

void CollectionManager::removeCollection(const QString& collectionId) {
    auto it = std::find_if(m_collections.begin(), m_collections.end(),
                           [&](const std::shared_ptr<Collection>& c) { return c->name() == collectionId; });

    if (it != m_collections.end()) {
        auto collection = *it;

        for (const auto& file : collection->files()) {
            m_fileLookup.remove(file->id());
        }

        m_collections.erase(it);
        emit collectionRemoved(collectionId);
    }
}

const QList<std::shared_ptr<Collection>>& CollectionManager::collections() const {
    return m_collections;
}

std::shared_ptr<Collection> CollectionManager::findCollectionById(const QString& id) const {
    for (const auto& collection : m_collections) {
        if (collection->name() == id) {
            return collection;
        }
    }
    return nullptr;
}

std::shared_ptr<CollectionFile> CollectionManager::findFileById(const QString& id) const {
    return m_fileLookup.value(id, nullptr);
}
