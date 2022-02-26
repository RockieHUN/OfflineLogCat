#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    stringList = new QStringList();

    stringList->append("ASD");
    stringList->append("BSDSADDSADASDASDASDASASDAA");

    //models
    stringListModel = new QStringListModel();
    stringListModel->setStringList(*stringList);

    //window
    window = new QWidget();

    //layouts
    mainVerticalLayout = new QVBoxLayout();

    //widgets
    listView = new CustomListView();
    listView->setModel(stringListModel);
    listView->setAcceptDrops(true);

    searchBar = new QLineEdit();

    //add views to layouts
    mainVerticalLayout->addWidget(searchBar);
    mainVerticalLayout->addWidget(listView);

    setCentralWidget(window);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    window->setLayout(mainVerticalLayout);
    setAcceptDrops(true);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasUrls()){
        if (event->mimeData()->urls().size() > MAX_NUM_OF_FILES){
            return;
        }
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    foreach (const QUrl &url, event->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        qDebug() << "Dropped file:" << fileName;
    }
}
