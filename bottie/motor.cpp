#include "motor.hpp"

QList<Motor*> Motor::Motors;

Motor::Motor(int channel)
{
    this->Channel = channel;
    Syslog::Log("Registering new offline motor on channel " + QString::number(channel));
    this->Speed = 0;
}

Motor::~Motor()
{
    Syslog::Log("Unregistered motor on channel " + QString::number(this->Channel));
}
