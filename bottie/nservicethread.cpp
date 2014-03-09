#include "nservicethread.hpp"

NServiceThread::NServiceThread(int Descriptor, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = Descriptor;
    this->tcpSocket = NULL;
    this->Connected = true;
}

NServiceThread::~NServiceThread()
{
    delete this->tcpSocket;
}

void NServiceThread::Disconnect()
{
    this->Connected = false;
    tcpSocket->disconnectFromHost();
    tcpSocket->waitForDisconnected();
}

void NServiceThread::Send(QString text)
{
    text += "\n";
    tcpSocket->write(text.toUtf8());
    tcpSocket->flush();
}

void NServiceThread::run()
{
    this->tcpSocket = new QTcpSocket();
    if (!this->tcpSocket->setSocketDescriptor(socketDescriptor))
    {
        Syslog::ErrorLog("Unable to bind to descriptor");
        emit error(tcpSocket->error());
        return;
    }

    while (Connected)
    {
        this->tcpSocket->waitForReadyRead(1);
        QString text(this->tcpSocket->readLine());
        //Send("PING");
        if (text != "")
        {
            text.replace("\n", "");
            text.replace("\r", "");
            Syslog::Log(text);
            if (text == "1++")
            {
                Motor::Motors.at(0)->ModifySpeed(100);
                Syslog::Log("Motor 1 boost 100");
            }
            if (text == "1--")
            {
                Motor::Motors.at(0)->ModifySpeed(-100);
                Syslog::Log("Motor 1 boost -100");
            }
            if (text == "2++")
            {
                Motor::Motors.at(1)->ModifySpeed(100);
                Syslog::Log("Motor 2 boost 100");
            }
            if (text == "2--")
            {
                Motor::Motors.at(1)->ModifySpeed(-100);
                Syslog::Log("Motor 2 boost -100");
            }
        }
        QThread::usleep(20000);
        //break;
    }
    Disconnect();
    return;
}

