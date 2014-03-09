#include "nservicethread.hpp"

NServiceThread::NServiceThread(int Descriptor, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = Descriptor;
    this->Connected = true;
}

void NServiceThread::Disconnect()
{
    this->Connected = false;
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}

void NServiceThread::Send(QString text)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << text;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket.write(block);
}

void NServiceThread::run()
{
    if (!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        Syslog::ErrorLog("Unable to bind to descriptor");
        emit error(tcpSocket.error());
        return;
    }

    while (Connected)
    {
        Send("hi");
        break;
    }
    Disconnect();
    return;
}
