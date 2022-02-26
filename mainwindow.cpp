#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setUpUI();
    logUtils = new LogUtils();
    setAcceptDrops(true);
    connectObjects();
}

void MainWindow::setUpUI(){
    //window
    window = new QWidget();

    //layouts
    mainVerticalLayout = new QVBoxLayout();

    //widgets
    listView = new CustomListView();
    searchBar = new SearchBar();

    //add views to layouts
    mainVerticalLayout->addWidget(searchBar);
    mainVerticalLayout->addWidget(listView);

    setCentralWidget(window);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    window->setLayout(mainVerticalLayout);
}

void MainWindow::connectObjects(){
    connect(searchBar, &QLineEdit::textChanged, logUtils, &LogUtils::filterLogs);
    connect(logUtils, &LogUtils::onLogsFiltered, listView, &CustomListView::updateLogList);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasUrls()){
        //TODO: check file type
        if (event->mimeData()->urls().size() > MAX_NUM_OF_FILES || !event->mimeData()->urls()[0].fileName().endsWith(".log")){
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
        logUtils->readFile(filePath);
        listView->updateList(logUtils->getLogs());
    }
}

MainWindow::~MainWindow(){
    delete window;
    delete mainVerticalLayout;
    delete listView;
    delete searchBar;
    delete logUtils;
}
