#include "logUtils.h"

LogUtils::LogUtils()
{
    logList = new QList<QString>;
}


void LogUtils::readFile(QString filePath){
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)){
        logList->clear();
        QTextStream stream (&file);
        while (!stream.atEnd()){
            QString line = stream.readLine();
            logList->append(line);
        }

        file.close();
    }
}

QList<QString>* LogUtils::getLogs(){
    return logList;
}

void LogUtils::filterLogs(const QString &newText){
    QList filteredLogs = logList->filter(newText);
    emit onLogsFiltered(filteredLogs);

    //for (int i =0; i<filteredLogs.size();i++){
    //    qDebug()<<filteredLogs[i];
    //}
}


LogUtils::~LogUtils(){
    delete logList;
}
