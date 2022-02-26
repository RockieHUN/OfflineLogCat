#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>
#include <QLineEdit>
#include <QMainWindow>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include "customlistview.h"
#include "logUtils.h"

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

    LogUtils * fileUtils;

    void setUpUI();


    //widgets
    QVBoxLayout * mainVerticalLayout;
    QWidget * window;
    QLineEdit * searchBar;

    //listView
    CustomListView * listView;


signals:

};

#endif // MAINWINDOW_H
