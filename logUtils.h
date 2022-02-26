#ifndef LOGUTILS_H
#define LOGUTILS_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QDebug>

class LogUtils : public QObject
{
    Q_OBJECT
public:
    LogUtils();
    ~LogUtils();
    void readFile(QString filePath);
    QList<QString>* getLogs();


private:
    QList<QString> *logList;

public slots:
    void filterLogs(const QString &newText);

signals:
    void onLogsFiltered(QList<QString> newList);

};

#endif // LOGUTILS_H
