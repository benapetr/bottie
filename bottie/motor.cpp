#include "motor.hpp"

QList<Motor*> Motor::Motors;

Motor::Motor(int channel)
{
    this->Channel = channel;
    this->Online = false;
    Syslog::Log("Registering new offline motor on channel " + QString::number(channel));
    this->Speed = 0;
    this->bSpeed = 0;
}

Motor::~Motor()
{
    Syslog::Log("Unregistered motor on channel " + QString::number(this->Channel));
}

bool Motor::IsOnline()
{
    return this->Online;
}

void Motor::Connect()
{
    if (this->IsOnline())
    {
        Syslog::Log("Not connecting motor which is online");
        return;
    }
    this->th = new MotorTh(this);
    this->th->start();
    Syslog::Log("Motor is online on ch: " + QString::number(this->Channel));
    this->Online = true;
}

void Motor::ModifySpeed(int speed)
{
    this->bSpeed = this->bSpeed + speed;
    if (this->bSpeed < 0)
    {
        this->bSpeed = 0;
    }
    if (this->bSpeed < 200)
    {
        this->Speed = 0;
    } else
    {
        this->Speed = this->bSpeed;
    }
}

MotorTh::MotorTh(Motor *Mx)
{
    this->mx = Mx;
}

MotorTh::~MotorTh()
{

}

void MotorTh::run()
{
    while (mx->IsOnline())
    {
        int speed = MINIMAL_SPEED;
        if (mx->Speed > MINIMAL_SPEED)
        {
            speed = mx->Speed;
        }
        digitalWrite(mx->Channel, LOW);
        QThread::usleep(5000 - speed);
        digitalWrite(mx->Channel, HIGH);
        QThread::usleep(speed);
    }
}
