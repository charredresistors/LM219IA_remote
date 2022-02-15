/*-------------------------------------------------------------/
/                   Line Magnetic  LM-219IA                    /
/                   Remote Control Firmware                    /
/                                                              /
/   Basic firmware for the LM-219IA receiver board using an    /
/   AT89C2051 and the SDCC pipeline.                           /
/                                                              /
/   Motor up is defined as P3.0 = 1; P3.1 = 0                  /
/   Motor down is defined as P3.0 = 0; P3.1 = 1                /
/   Mute is defined as P1.0 = 0                                /
/   Unmute is defined as P1.0 = 1                              /
/   LED on is defined as P3.7 = 0                              /
/   LED off is defined as P3.7 = 1                             /
/-------------------------------------------------------------*/

#define MICROCONTROLLER_AT89CX051
#include <mcs51reg.h>
#include "delay.h"

// Blink LED at approx 1 sec interval, slightly > 30s
void blink(void){
    P3_7 = 1;
    delay_sec(3);
    P3_7 = 0; // Last write leaves the LED on
    delay_sec(3);
}

// Main Loop
void main(void)
{
    while(1) {
        P1_0 = 0; // Mute - startup requres >30s mute
        int i;
        for(i=0; i<30; i++){ // Blink LED while muted
            blink();
        }
        P1_0 = 1; // Unmute for normal amp funtion
        for(;;){} //Wait forEVER
    }
}