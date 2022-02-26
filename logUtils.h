#ifndef LOGUTILS_H
#define LOGUTILS_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QDebug>

class LogUtils
{
public:
    LogUtils();
    ~LogUtils();
    void readFile(QString filePath);
    QList<QString>* getLogs();


private:
    QList<QString> *logList;

};

#endif // LOGUTILS_H
