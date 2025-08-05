#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <DockWidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMenu();
    setupDocking();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMenu() {
    QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
    QAction* openCollectionAction = new QAction(tr("Open Collection..."), this);
    connect(openCollectionAction, &QAction::triggered, this, &MainWindow::openCollection);
    fileMenu->addAction(openCollectionAction);
}

void MainWindow::setupDocking() {
    m_dockManager = new ads::CDockManager(this);
    setCentralWidget(m_dockManager);

    QDockWidget* explorerDock = new QDockWidget(tr("Explorer"), this);
    m_treeWidget = new QTreeWidget(explorerDock);
    m_treeWidget->setHeaderLabel("Collections");
    explorerDock->setWidget(m_treeWidget);
    addDockWidget(Qt::LeftDockWidgetArea, explorerDock);

    connect(m_treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::onTreeItemClicked);
}

void MainWindow::openCollection() {
    //QString path = QFileDialog::getExistingDirectory(this, tr("Select Collection Directory"));
    //if (!path.isEmpty()) {
    //    loadCollectionFromPath(path);
    //}
}

void MainWindow::loadCollectionFromPath(const QString& path) {
    //auto collection = m_collectionManager->loadCollection(path);
    //QTreeWidgetItem* collectionItem = new QTreeWidgetItem(m_treeWidget, QStringList() << collection->name());

    //for (const auto& file : collection->files()) {
    //    QTreeWidgetItem* fileItem = new QTreeWidgetItem(collectionItem, QStringList() << file->id());
    //    fileItem->setData(0, Qt::UserRole, file->id());
    //}

    //m_treeWidget->expandItem(collectionItem);
}

void MainWindow::onTreeItemClicked(QTreeWidgetItem* item, int column) {
    //QString fileId = item->data(0, Qt::UserRole).toString();
    //auto file = m_collectionManager->findFileById(fileId);
    //if (file) {
    //    openFileInDock(file);
    //}
}

void MainWindow::openFileInDock(std::shared_ptr<CollectionFile> file) {
    //QWidget* viewer = ViewerFactory::createViewer(file);
    //if (!viewer) return;

    //auto* dock = new ads::CDockWidget(file->id(), viewer);
    //m_dockManager->addDockWidget(ads::CenterDockWidgetArea, dock);
    //file->setIsOpen(true);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    // Placeholder: Save session logic would go here
    //event->accept();
}
