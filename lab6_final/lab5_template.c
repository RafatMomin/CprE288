/*/**
 * lab5_template.c
 *
 * Template file for CprE 288 Lab 5
 *
 * @author Zhao Zhang, Chad Nelson, Zachary Glanz
 * @date 08/14/2016
 *
 * @author Phillip Jones, updated 6/4/2019
 * @author Diane Rover, updated 2/25/2021, 2/17/2022
 */
/*
#include "button.h"
#include "timer.h"
#include "lcd.h"
#include"uart.h"
*/
//#include "cyBot_uart.h"  // Functions for communicating between CyBot and Putty (via UART1)
                         // PuTTy: Baud=115200, 8 data bits, No Flow Control, No Parity, COM1
/*
#include "cyBot_Scan.h"  // Scan using CyBot servo and sensors
void cyBot_sendString(char data[]);

#warning "Possible unimplemented functions"
#define REPLACEME 0



int main(void) {
	button_init();
	timer_init(); // Must be called before lcd_init(), which uses timer functions
	lcd_init();
*/
  // initialize the cyBot UART1 before trying to use it

  // (Uncomment ME for UART init part of lab)
	// cyBot_uart_init_clean();  // Clean UART1 initialization, before running your UART1 GPIO init code

	// Complete this code for configuring the GPIO PORTB part of UART1 initialization (your UART1 GPIO init code)
//      SYSCTL_RCGCGPIO_R |= 1 << 1;
//      while ((SYSCTL_PRGPIO_R & 0x02) == 0) {};
//      GPIO_PORTB_DEN_R |= 0x03;
//      GPIO_PORTB_AFSEL_R |= 0x03;
//      GPIO_PORTB_PCTL_R &= 0xFFFFFF00;     // Force 0's in the desired locations
//      GPIO_PORTB_PCTL_R |= 0x11;     // Force 1's in the desired locations
//		 // Or see the notes for a coding alternative to assign a value to the PCTL field
//
//    // (Uncomment ME for UART init part of lab)
//		 cyBot_uart_init_last_half();  // Complete the UART device configuration

		// Initialize the scan
	  // cyBOT_init_Scan();
		// Remember servo calibration function and variables from Lab 3

/*
	uart_init();

	// YOUR CODE HERE
    int userInput;
	char buffer[20];
	int i = 0;
	char data[50];
	while(i<20){
	    userInput = uart_receive();
	    if(userInput == '\r'){
	        break;
	    }
	    sprintf(data, "%c", userInput);
	    uart_sendStr(data);
	    buffer[i] = userInput;
//	    sprintf(data, "%s\n%i", buffer, i);
//	    lcd_printf(data);
	    i++;
	}
	sprintf(data, "%s\n%i", buffer, i);
	lcd_printf(data);
*/

//    while(1)
//	{
//	        userInput = uart_receive();
//	        char data[50];
//            sprintf(data, "Pressed %c", userInput);
//            uart_sendStr(data);
//            lcd_printf("Got a %c",userInput);
//	}

//}

/*
void cyBot_sendString(char data[])
{
    int dataLen = strlen(data);
    int i;
    for (i = 0; i < dataLen; i++)
    {
        cyBot_sendByte(data[i]);
    }
    cyBot_sendByte('\n');
}
*/
