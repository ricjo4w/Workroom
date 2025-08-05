#include "collectionfile.h"

CollectionFile::CollectionFile(QString id, Type type)
    : m_id(std::move(id)), m_type(type), m_isOpen(false)
{
}

CollectionFile::~CollectionFile() = default;

QString CollectionFile::id() const {
    return m_id;
}

CollectionFile::Type CollectionFile::type() const {
    return m_type;
}

bool CollectionFile::isOpen() const {
    return m_isOpen;
}

void CollectionFile::setIsOpen(bool open) {
    m_isOpen = open;
}
