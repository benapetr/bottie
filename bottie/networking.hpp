#ifndef NETWORKING_H
#define NETWORKING_H

#include <QObject>
#include <QTcpServer>
#include <QNetworkSession>
#include <QThread>
#include "networkserver.hpp"
#include "syslog.hpp"

class Networking : public QObject
{
        Q_OBJECT
    public:
        Networking(QObject *parent = 0) : QObject(parent)
        {
            Reset();
        }
        void Reset();
        void Listen();
        bool IsConnected();
        QString IP;
    public slots:
        void run();
        void SessionOpen();
    private:
        NetworkServer *server;
        QNetworkSession *session;
        bool Connected;
};

#endif // NETWORKING_H
