#include "networkserver.hpp"

NetworkServer::NetworkServer(QObject *parent) : QTcpServer(parent)
{
}

void NetworkServer::incomingConnection(int socketDescriptor)
{
    NServiceThread *thread = new NServiceThread(socketDescriptor, this);
    //Syslog::Log("in");
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
