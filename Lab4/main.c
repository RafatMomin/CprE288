

/**
 * main.c
 */
#include <stdio.h>
#include <stdint.h>
#include "lcd.h"
#include "open_interface.h"
#include "Timer.h"
#include "cyBot_uart.h"
#include "cyBot_Scan.h"
#include <inc/tm4c123gh6pm.h>


int main(void)
{
    //char data;
    timer_init(); //initializes the timer
    lcd_init();
    cyBot_uart_init(); //cyBot_uart.h initializing
   // data = 'm';
   // cyBot_sendByte(data);
    int value;

    char text[50];   // defining character

    value = cyBot_getByte(); // using this function to receive text from cyBot

    sprintf(text, "%d", value); // taking the char value to int variable

       lcd_puts(text);          // printing text
	return 0;
}


/*
#include <stdio.h>
#include <stdint.h>
#include "lcd.h"
#include "open_interface.h"
#include "Timer.h"
#include "cyBot_uart.h"
#include "cyBot_Scan.h"
#include <inc/tm4c123gh6pm.h>

#define MAX_OBJECTS 5 // Maximum number of objects to detect

typedef struct {
    int angle;
    int distance;
    int width;
} Object;

int main(void)
{
    // Initialize peripherals
    timer_init();
    lcd_init();
    cyBot_uart_init();

    // Array to hold object data
    Object objects[MAX_OBJECTS];
    int num_objects = 0;

    // Receive sensor data from CyBot
    cyBot_Scan_start(); // Start scanning
    delay_ms(2000); // Delay for scan to complete

    // Parse sensor data
    for (int i = 0; i < 180; i += 5) {
        int distance = cyBot_getPing(i); // Get distance at angle i
        if (distance > 0 && num_objects < MAX_OBJECTS) {
            // Store object data
            objects[num_objects].angle = i;
            objects[num_objects].distance = distance;
            objects[num_objects].width = 5; // Assume object width for now
            num_objects++;
        }
    }

    // Find object with smallest width
    int smallest_width = objects[0].width;
    int smallest_index = 0;
    for (int i = 1; i < num_objects; i++) {
        if (objects[i].width < smallest_width) {
            smallest_width = objects[i].width;
            smallest_index = i;
        }
    }

    // Point CyBot's sensor towards object with smallest width
    int target_angle = objects[smallest_index].angle;
    // Code to control servo motor and point sensor to target_angle goes here

    // Display object information
    char text[50];
    sprintf(text, "Angle: %d", objects[smallest_index].angle);
    lcd_puts(text);
    sprintf(text, "Distance: %d cm", objects[smallest_index].distance);
    lcd_puts(text);
    sprintf(text, "Width: %d degrees", objects[smallest_index].width);
    lcd_puts(text);

    return 0;
}*/
