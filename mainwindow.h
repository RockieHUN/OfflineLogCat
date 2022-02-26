#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>
#include <QMainWindow>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include "customlistview.h"
#include "logUtils.h"
#include "searchbar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

public:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    ~MainWindow();
private:
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 600;
    const int MAX_NUM_OF_FILES = 1;

    LogUtils * logUtils;

    void setUpUI();
    void connectObjects();


    //widgets
    QVBoxLayout * mainVerticalLayout;
    QWidget * window;
    SearchBar * searchBar;

    //listView
    CustomListView * listView;


signals:

};

#endif // MAINWINDOW_H
