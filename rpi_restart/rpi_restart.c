#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#ifndef PIN_NUMBER
#error "PIN_NUMBER not defined!"
#endif

void interrupt(void)
{
    if (system("sudo reboot")) fprintf(stderr, "Unable to reboot Pi.");
}

int main(void)
{
    wiringPiSetup();
    pinMode(PIN_NUMBER, INPUT);

    #ifdef PULL_UP
    pullUpDnControl(PIN_NUMBER, PUD_UP);
    #endif

    wiringPiISR(PIN_NUMBER, INT_EDGE_FALLING, &interrupt);

    // Wait until the end of time
    while (1) delay(500);
}
