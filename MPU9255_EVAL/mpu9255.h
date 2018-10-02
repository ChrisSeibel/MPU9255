#ifndef MPU9255_H
#define MPU9255_H

#include "headers.h"
#include "mpu9255_registers.h"

class MPU9255 : public QObject
{
    Q_OBJECT
public:
    explicit MPU9255(int intPin);

    //get data
    float get_roll() {return _roll;}
    float get_pitch() {return _pitch;}
    vector get_acceleration() {return _acc;}

private:
    void MPU_Write(const uint8_t reg, const uint8_t data, const int dev = mpu_9255);
    int8_t MPU_Read(const uint8_t reg, const int dev = mpu_9255);


    int _intPin;
    float _pitch, _roll;
    vector _acc;
    QTimer *readAcc_timer;

public slots:
    void start();
    void stop();
private slots:
    void readAccelerometer();
};

#endif // MPU9255_H
