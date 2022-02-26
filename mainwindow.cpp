#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setUpUI();
    fileUtils = new LogUtils();
    setAcceptDrops(true);
}

void MainWindow::setUpUI(){
    //window
    window = new QWidget();

    //layouts
    mainVerticalLayout = new QVBoxLayout();

    //widgets
    listView = new CustomListView();
    searchBar = new QLineEdit();

    //add views to layouts
    mainVerticalLayout->addWidget(searchBar);
    mainVerticalLayout->addWidget(listView);

    setCentralWidget(window);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    window->setLayout(mainVerticalLayout);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasUrls()){
        if (event->mimeData()->urls().size() > MAX_NUM_OF_FILES || !event->mimeData()->urls()[0].fileName().endsWith(".txt")){
            return;
        }
        else{
            event->acceptProposedAction();
        }
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    event->mimeData()->urls()[0].toLocalFile();
    foreach (const QUrl &url, event->mimeData()->urls()) {
        QString filePath = url.toLocalFile();
        qDebug() << "Dropped file:" << filePath;
        fileUtils->readFile(filePath);
        listView->updateList(fileUtils->getLogs());
    }
}

MainWindow::~MainWindow(){
    delete window;
    delete mainVerticalLayout;
    delete listView;
    delete searchBar;
    delete fileUtils;
}
