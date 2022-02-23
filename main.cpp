#include <QApplication>
#include "offlinelogcat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    OfflineLogCat offlinelogcat;

    return a.exec();
}
