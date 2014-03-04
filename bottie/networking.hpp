#ifndef NETWORKING_H
#define NETWORKING_H

#include <QObject>
#include <QTcpServer>
#include <QThread>
#include "syslog.hpp"

class Networking : public QObject
{
        Q_OBJECT
    public:
        Networking(QObject *parent = 0) : QObject(parent) {}
    public slots:
        void run();
};

#endif // NETWORKING_H
