#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <QList>
#include <QThread>
#include <unistd.h>
#include "syslog.hpp"

class Motor
{
    public:
        static QList<Motor*> Motors;
        Motor(int channel);
        ~Motor();
        int Channel;
        int Speed;
};

#endif // MOTOR_HPP
