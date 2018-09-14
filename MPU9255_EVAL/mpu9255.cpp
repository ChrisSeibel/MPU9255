#include "mpu9255.h"

MPU9255::MPU9255(int intPin)
{
    // set up pins
    _intPin = intPin;
    pinMode(_intPin, INPUT);

    // configure registers
    wiringPiI2CWriteReg8(mpu_9255, PWR_MGMT_1, 0x00);
    wiringPiI2CWriteReg8(mpu_9255, PWR_MGMT_2, 0x00);

    //initialize timers
    readAcc_timer = new QTimer(this);
    connect(readAcc_timer, SIGNAL(timeout()), this, SLOT(readAccelerometer()));
}

void MPU9255::start()
{
    readAcc_timer->start(MPU_READ_INTERVAL);
}

void MPU9255::stop()
{
    readAcc_timer->stop();
}

void MPU9255::readAccelerometer()
{
    int16_t acc_x = wiringPiI2CReadReg8(mpu_9255, ACCEL_XOUT_H) << 8 + wiringPiI2CReadReg8(mpu_9255, ACCEL_XOUT_L);
    int16_t acc_y = wiringPiI2CReadReg8(mpu_9255, ACCEL_YOUT_H) << 8 + wiringPiI2CReadReg8(mpu_9255, ACCEL_YOUT_L);
    int16_t acc_z = wiringPiI2CReadReg8(mpu_9255, ACCEL_ZOUT_H) << 8 + wiringPiI2CReadReg8(mpu_9255, ACCEL_ZOUT_L);

    qDebug() << "Acc raw: " << acc_x << " " << acc_y << " " << acc_z;

    _acc.x = acc_x;
    _acc.y = acc_y;
    _acc.z = acc_z;
}
