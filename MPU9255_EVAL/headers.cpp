#include "headers.h"

//this file is needed to create the file-descriptors for the I²C and SPI bus

int pca_motors;
int mpu_9255;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    //from https://www.arduino.cc/reference/en/language/functions/math/map/
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
