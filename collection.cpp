#include "collection.h"
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>

// Stub file type detection and dummy loading (to be replaced with real logic)
std::shared_ptr<CollectionFile> createMockFile(const QString& filePath);

Collection::Collection(const QString& path)
    : m_path(path), m_name(QFileInfo(path).fileName())
{
    loadFiles();
}

QString Collection::name() const {
    return m_name;
}

QString Collection::path() const {
    return m_path;
}

const QList<std::shared_ptr<CollectionFile>>& Collection::files() const {
    return m_files;
}

std::shared_ptr<CollectionFile> Collection::findById(const QString& id) const {
    for (const auto& file : m_files) {
        if (file->id() == id) return file;
    }
    return nullptr;
}

void Collection::loadFiles() {
    //QDir dir(m_path);
    //QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::NoSymLinks);
    //for (const QFileInfo& fileInfo : fileList) {
    //    auto file = createMockFile(fileInfo.absoluteFilePath());
    //    if (file) {
    //        m_files.append(file);
    //    }
    //}
}

// Mock file factory for demonstration (normally you'd inspect file extension, etc.)
//#include "CollectionFile.h"
//class MockFile : public CollectionFile {
//public:
//    MockFile(const QString& id) : CollectionFile(id, CollectionFile::Type::Unknown) {}
//    void load(const QString&) override {}
//    void exportTo(const QString&) const override {}
//};

//std::shared_ptr<CollectionFile> createMockFile(const QString& filePath) {
//    return std::make_shared<MockFile>(QFileInfo(filePath).fileName());
//}
