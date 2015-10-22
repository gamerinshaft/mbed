#include "mbed.h"

Serial pc(USBTX, USBRX);

class Counter
{
public:
    Counter(PinName pin):_interrupt(pin), _digital(pin), num(0)
    {
        _interrupt.rise(this, &Counter::handleClick);
    };

    int state()
    {
        return num;
    };

    void handleClick()
    {
        wait(0.1);
        if(_digital)
        {
            num++;
            pc.printf("%i times clicked.\r\n",num);
        }
    };


private:
    InterruptIn _interrupt;
    DigitalIn _digital;
    int num;
};

Counter counter(p2);

int main()
{
    pc.baud(9600);
}