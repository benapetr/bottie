#include "networking.hpp"

void Networking::Reset()
{
    this->server = NULL;
    this->Connected = false;
    this->session = NULL;
    this->Listen();
}

void Networking::Listen()
{
    if (this->Connected)
    {
        return;
    }
    server = new NetworkServer(this);
    if (!server->listen(QHostAddress::Any, 120))
    {
        Syslog::ErrorLog("Unable to open the listener");
        delete server;
        server = NULL;
        return;
    }
}

bool Networking::IsConnected()
{
    return this->IsConnected();
}

void Networking::run()
{
    Syslog::Log("Listener is up");
}

void Networking::SessionOpen()
{

}
