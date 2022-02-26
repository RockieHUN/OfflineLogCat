#include "customlistview.h"

CustomListView::CustomListView()
{
}


void CustomListView::updateList(QStringList* list){
    clear();
    addItems(*list);
}

void CustomListView::updateLogList(QList<QString> filteredLogs){
    QStringList tempList;
    for (int i = 0; i<filteredLogs.size(); i++){
        tempList.append(filteredLogs[i]);
    }
    updateList(&tempList);
}
