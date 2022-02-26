#include "logUtils.h"

LogUtils::LogUtils()
{

}


void LogUtils::readFile(QString filePath){
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)){
        logList = new QList<QString>;
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


LogUtils::~LogUtils(){
    delete logList;
}
