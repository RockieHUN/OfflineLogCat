#ifndef CUSTOMLISTVIEW_H
#define CUSTOMLISTVIEW_H

#include <QListWidget>
#include <QAbstractItemView>
#include <QStringList>

class CustomListView : public QListWidget
{
public:
    CustomListView();
    void updateList(QStringList* list);

public slots:
    void updateLogList(QList<QString> filteredLogs);
};

#endif // CUSTOMLISTVIEW_H
