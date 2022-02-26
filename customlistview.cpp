#include "customlistview.h"

CustomListView::CustomListView()
{
}


void CustomListView::updateList(QStringList* list){
    clear();
    addItems(*list);
}
