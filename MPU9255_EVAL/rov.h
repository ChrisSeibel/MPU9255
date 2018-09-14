#ifndef ROV_H
#define ROV_H

#include "headers.h"
#include "mpu9255.h"

class MPU9255;

class ROV : public QObject
{
    Q_OBJECT
public:
    explicit ROV(QObject *parent = nullptr);

private:
    QTimer *timer1;
    MPU9255 *mpu;

    QString msg;

signals:

private slots:
    void timerInterrupt();

public slots:
    int initialize();
    void operate();
};

#endif // ROV_H
