#include "mbed.h"

DigitalOut myled(p7);

int main()
{
    while(1){
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}