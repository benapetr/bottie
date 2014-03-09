#include "networkserver.hpp"

NetworkServer::NetworkServer(QObject *parent) : QTcpServer(parent)
{
}

void NetworkServer::incomingConnection(qintptr socketDescriptor)
{
    NServiceThread *thread = new NServiceThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
