#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <QList>
#include <unistd.h>

class Motor
{
    public:
        static QList<Motor*> Motors;
        Motor(int channel);
        ~Motor();
        int Channel;
};

#endif // MOTOR_HPP
