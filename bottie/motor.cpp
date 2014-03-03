#include "motor.hpp"

QList<Motor*> Motor::Motors;

Motor::Motor(int channel)
{
    this->Channel = channel;
}

Motor::~Motor()
{

}
