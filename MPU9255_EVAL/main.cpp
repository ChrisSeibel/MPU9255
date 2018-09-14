#include <QCoreApplication>
#include "rov.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ROV rov;
    rov.initialize();
    rov.operate();

    return a.exec();
}
