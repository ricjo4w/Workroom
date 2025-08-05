#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <memory>
#include "DockManager.h"
#include "collectionmanager.h"
#include "collectionfile.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


/**
 * @class MainWindow
 * @brief Main application window containing the dock system and file explorer.
 *
 * The MainWindow class manages the overall UI of the application, including the
 * dockable workspace powered by Qt Advanced Docking System (ADS) and a tree-based
 * explorer for browsing and opening files from loaded collections. It connects
 * user actions like file selection, session loading, and viewer instantiation to
 * the appropriate backend components such as the CollectionManager and viewer widgets.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Constructs the MainWindow and initializes its layout and components.
     * @param parent The parent widget (default nullptr).
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow.
     */
    ~MainWindow();

protected:
    /**
     * @brief Overridden close event used to auto-save the session on exit.
     * @param event The close event to be accepted or ignored.
     */
    void closeEvent(QCloseEvent* event) override;

private slots:
    /**
     * @brief Opens a file explorer dialog to load a new collection.
     */
    void openCollection();

    /**
     * @brief Handles the user clicking on a file item in the tree explorer.
     * @param item The clicked tree item.
     * @param column The column index that was clicked.
     */
    void onTreeItemClicked(QTreeWidgetItem* item, int column);

private:
    /**
     * @brief Initializes the menu bar and associated actions.
     */
    void setupMenu();

    /**
     * @brief Initializes the dock manager and explorer dock widget.
     */
    void setupDocking();

    /**
     * @brief Loads a collection from disk and populates the explorer.
     * @param path The path to the collection's directory or manifest.
     */
    void loadCollectionFromPath(const QString& path);

    /**
     * @brief Opens a file in a new docked viewer window.
     * @param file The file to open.
     */
    void openFileInDock(std::shared_ptr<CollectionFile> file);

    Ui::MainWindow *ui;
    std::unique_ptr<CollectionManager> m_collectionManager; ///< Manages all collections and files.
    ads::CDockManager* m_dockManager;                       ///< Manages dockable layout and widgets.
    QTreeWidget* m_treeWidget;                              ///< Explorer view for collections and files.
};
#endif // MAINWINDOW_H
