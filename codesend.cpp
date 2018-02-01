/*
Usage: ./codesend <decimalcode>
@author markushaug <mh@haugmarkus.de>

Thanks to ninjablocks/433Utils for the 433 utils
*/
#include "../rc-switch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
     
int
main(int argc, char *argv[])
{
    // This pin is not the first pin on the RPi GPIO header!
    // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
    // for more information.
    
    int PIN(0), // Set gpio-pin to 0
        protocol(0), // A value of 0 will use rc-switch's default value
        pulseLength(0); // Set pulseLength to 0 for default

    // If no command line argument is given, print the help text
    if (argc != 2) {
      printf("Usage: %s <decimalcode>\n", *argv);
      exit(0);
    }
    
    // Convert the second argument to integer
    int code = atoi(*(argv+1));
    
    // If wiringPi is not installed, the program will be terminated.
    if (wiringPiSetup () == -1) return 1;
    
    printf("sending code[%i]\n", code);
    RCSwitch switch = RCSwitch(); // New RCSwitch Object
    switch.enableTransmit(PIN); // Passing PIN by value
    switch.send(code, 24); // send 3-Byte long code
    
    return 0;
}
