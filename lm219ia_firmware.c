/*-------------------------------------------------------------/
/                   Line Magnetic  LM-219IA                    /
/                   Remote Control Firmware                    /
/-------------------------------------------------------------*/
#define MICROCONTROLLER_AT89CX051
#include <mcs51reg.h>
#include <delay.h>

// Blink LED at a 1 sec interval
void blink(void){
    P3_7 = 1;
    delay_sec(1);
    P3_7 = 0;
    delay_sec(1);
}

// Mute
void mute(void){
    P1_0 = 0;
}

//Un-mute
void unmute(void){
    P1_0 = 1;
}

// Main Loop
void main(void)
{
    while(1) {
        mute();  //Beginning of startup routine
        int i;
        for(i=0; i<30; i++)
            blink();
        unmute(); //End of startup routine
        for(;;){} //Wait forEVER
    }
}