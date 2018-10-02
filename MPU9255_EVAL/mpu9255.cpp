#include "mpu9255.h"

MPU9255::MPU9255(int intPin)
{
    // set up pins
    _intPin = intPin;
    pinMode(_intPin, INPUT);

    //reset MPU
    wiringPiI2CWriteReg8(mpu_9255, PWR_MGMT_1, 0x80);
    QThread::msleep(10);

    //check WHO_AM_I register
    uint8_t ID = MPU_Read(WHO_AM_I);
    if (ID == 0x73){
        qDebug() << "MPU-9255 ready!";
    }
    else {
        qDebug() << "[ERROR] WHO_AM_I = " << showbase << uppercasedigits << hex << ID << " not as expected.\n" ;
    }


    // configure registers
    wiringPiI2CWriteReg8(mpu_9255, PWR_MGMT_1, 0x00); //unset SLEEP
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
    //int16_t acc_x = wiringPiI2CReadReg8(mpu_9255, ACCEL_XOUT_H) << 8 + wiringPiI2CReadReg8(mpu_9255, ACCEL_XOUT_L);
    int16_t acc_x = (MPU_Read(ACCEL_XOUT_H) << 8) | MPU_Read(ACCEL_XOUT_L);
    //int16_t acc_y = (MPU_Read(ACCEL_YOUT_H) << 8) | MPU_Read(ACCEL_YOUT_L);
    //int16_t acc_z = (MPU_Read(ACCEL_ZOUT_H) << 8) | MPU_Read(ACCEL_ZOUT_L);

    qDebug() << "Acc raw: " << acc_x ;//<< " " << acc_y << " " << acc_z;

    _acc.x = acc_x;
    //_acc.y = acc_y;
    //_acc.z = acc_z;
}

void MPU9255::MPU_Write(const uint8_t reg, const uint8_t data, const int dev){
    wiringPiI2CWriteReg8(dev, reg, data);
}

int8_t MPU9255::MPU_Read(const uint8_t reg, const int dev){
    int8_t data = wiringPiI2CReadReg8(dev, reg);
    return data;
}
