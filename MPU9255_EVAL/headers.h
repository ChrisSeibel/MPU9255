#ifndef HEADERS_H
#define HEADERS_H

#include <QDebug>

#include <iostream>

//libraries of Qt
#include <QObject>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QList>
#include <QProcess>

//hardware
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringPiSPI.h>

//load config file
#include "config.h"
#include "hardware_map.h"

//global variables and file-descriptors
extern int mpu_9255;

struct vector {
    float x, y, z;
};

long map(long x, long in_min, long in_max, long out_min, long out_max);

#endif // HEADERS_H
