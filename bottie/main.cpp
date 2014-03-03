#include <QCoreApplication>
#include <QList>
#include <QTimer>
#include "networking.hpp"
#include "motor.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Motor::Motors.append(new Motor(1));
    Motor::Motors.append(new Motor(2));
    Networking *network = new Networking(&a);
    // This will run the task from the application event loop.
    QTimer::singleShot(0, network, SLOT(run()));
    return a.exec();
}
