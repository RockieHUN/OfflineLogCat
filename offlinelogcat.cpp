#include "offlinelogcat.h"

OfflineLogCat::OfflineLogCat()
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
    listView = new QListView();
    listView->setModel(stringListModel);

    searchBar = new QLineEdit();

    //add views to layouts
    mainVerticalLayout->addWidget(searchBar);
    mainVerticalLayout->addWidget(listView);


    window->setLayout(mainVerticalLayout);

    window->show();
}
