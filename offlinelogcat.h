#ifndef OFFLINELOGCAT_H
#define OFFLINELOGCAT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QLineEdit>


class OfflineLogCat
{
public:
    OfflineLogCat();

private:
    QWidget * window;
    QVBoxLayout * mainVerticalLayout;

    //searchInput
    QLineEdit * searchBar;

    //listView
    QListView * listView;
    QStringListModel * stringListModel;
    QStringList * stringList;
};

#endif // OFFLINELOGCAT_H
