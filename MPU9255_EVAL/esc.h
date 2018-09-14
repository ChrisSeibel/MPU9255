#ifndef ESC_H
#define ESC_H

#include "headers.h"

class esc
{
public:
    esc(int channelPCA, int minL, int maxL, int minP, int maxP);
    void run(int speed);            //in %
    void stop();
private:
    int _minPulse, _maxPulse;   //value for _minLen/_maxLen
    int _minLen, _maxLen;       //in ms
    int _channel;
    int _currentSpeed;
};

#endif // ESC_H
