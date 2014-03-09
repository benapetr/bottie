#ifndef NETWORKSERVER_HPP
#define NETWORKSERVER_HPP

#include <QTcpServer>
#include "syslog.hpp"
#include "nservicethread.hpp"

class NetworkServer : public QTcpServer
{
        Q_OBJECT
    public:
        NetworkServer(QObject *parent = 0);

    protected:
        void incomingConnection(int socketDescriptor);

    private:

};

#endif // NETWORKSERVER_HPP
