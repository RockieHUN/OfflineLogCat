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

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

public:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private:
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 600;
    const int MAX_NUM_OF_FILES = 1;

    QVBoxLayout * mainVerticalLayout;
    QWidget * window;
    //searchInput
    QLineEdit * searchBar;

    //listView
    CustomListView * listView;
    QStringListModel * stringListModel;
    QStringList * stringList;

signals:

};

#endif // MAINWINDOW_H
