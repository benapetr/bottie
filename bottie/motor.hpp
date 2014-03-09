#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <QList>
#include <QThread>
#include <unistd.h>
#include <wiringPi.h>
#include "syslog.hpp"

#define MINIMAL_SPEED 20

class Motor;

class MotorTh : public QThread
{
        Q_OBJECT
    public:
        MotorTh(Motor *Mx);
        ~MotorTh();
        Motor *mx;
    protected:
        void run();
};

class Motor
{
    public:
        static QList<Motor*> Motors;

        Motor(int channel);
        ~Motor();
        bool IsOnline();
        void Connect();
        void ModifySpeed(int speed);
        int Channel;
        int bSpeed;
        int Speed;
    private:
        bool Online;
        MotorTh *th;
};

#endif // MOTOR_HPP
