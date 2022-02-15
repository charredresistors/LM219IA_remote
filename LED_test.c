/*-------------------------------------------------------------/
/                   Line Magnetic  LM-219IA                    /
/                   Remote Control Firmware                    /
/-------------------------------------------------------------*/

#define MICROCONTROLLER_AT89CX051
#include <mcs51reg.h>

// Delay funtion - wastes time in a NOP loop
void delay(void)
{
    int i, j;
    for(i=0; i<0xFF; i++)
        for(j=0; j<0xFF; j++);
}

// Main Loop that toggles an LED on and off
void main(void)
{
    while(1) {
        P1_0 = 1;
        delay();
        P1_0 = 0;
        delay();
    }
}