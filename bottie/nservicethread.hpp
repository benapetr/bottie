#ifndef NSERVICETHREAD_H
#define NSERVICETHREAD_H

#include <QString>
#include <QTcpSocket>
#include <QThread>
#include "syslog.hpp"
#include "motor.hpp"

class NServiceThread : public QThread
{
        Q_OBJECT
    public:
        NServiceThread(int Descriptor, QObject *parent);
        void Disconnect();
        void Send(QString text);
        bool Connected;

    protected:
        void run();

    signals:
        void error(QTcpSocket::SocketError socketError);

    private:
        int socketDescriptor;
        QTcpSocket tcpSocket;
};

#endif // NSERVICETHREAD_H
