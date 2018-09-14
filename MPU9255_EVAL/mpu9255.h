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
    void MPU_Write(uint8_t reg, uint8_t data);
    uint8_t MPU_Read(uint8_t reg);


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
