#include "rov.h"

ROV::ROV(QObject *parent) : QObject(parent)
{
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(timerInterrupt()));
}

int ROV::initialize(){
    qDebug() << "piROV 1.0 init...";

    //set up I²C
    mpu_9255 = wiringPiI2CSetup(MPU9255_ADDR);
    qDebug() << "\tI2C ready";

    //set up GPIOs
    wiringPiSetup();
    qDebug() << "\tGPIOs ready";

    //set up MPU9255
    mpu = new MPU9255(MPU_INT_PIN);
    qDebug() << "\tMPU9255 ready";

    qDebug() << "Initialization completed!";
    return 0;
}

void ROV::operate()
{
    timer1->start(1000);
    mpu->start();
}

void ROV::timerInterrupt(){
    qDebug() << "timerEvent";
    qDebug() << "acc: " << mpu->get_acceleration().x << " " << mpu->get_acceleration().y << " " << mpu->get_acceleration().z;
}
