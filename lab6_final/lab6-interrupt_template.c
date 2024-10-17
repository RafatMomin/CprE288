/**
 * lab6-interrupt_template.c
 *
 * Template file for CprE 288 Lab 6
 *
 * @author Diane Rover, 2/15/2020
 *
 */

#include "Timer.h"
#include "lcd.h"
#include "cyBot_Scan.h"  // For scan sensors

#include "uart-interrupt.h"

// Uncomment or add any include directives that you want to use
// #include "open_interface.h"
// #include "movement.h"
// #include "button.h"

// Your code can use the global variables defined in uart-interrupt.c
// They are declared with the extern qualifier in uart-interrupt.h, which makes the variables visible to this file.

#warning "Possible unimplemented functions"
#define REPLACEME 0

int main(void)
{
    //declarations
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();
    uart_interrupt_init();
    cyBOT_Scan_t scan;
    cyBOT_init_Scan(0b0111);

    // OPTIONAL
    //assign a value to command_byte if you want to know whether that ASCII code is received
    //note that command_byte is global shared variable read by the ISR
    //for example, try using a tab character as a command from PuTTY

    //variables
    int startScan = 0;
    int scanPosition = 0;

    //while loop starts program
    while (1)
    {
        //if received a letter byte
        if (command_flag)
        {
            lcd_printf("STARTED SCAN! %c", command_byte);
            //if statement for a g being entered
            if (command_byte == 'g')
            {
                //resets values of scan
                if (!startScan)
                {
                    startScan = 1;
                    scanPosition = 0;
                }
            }

            //if statement for an s being entered
            if (command_byte == 's')
            {
                //tests to see
                if(command_byte == 's'){
                    lcd_printf("STOPPED SCAN! %c", command_byte);
                    startScan = 0;
                }
            }
            //resets input flag
            command_flag = 0;
        }

        //if statement for scan
        if (startScan)
                {
                    //begins scan
                    cyBOT_Scan(scanPosition, &scan);
                    scanPosition += 2;

                    //if statement to test for a full scan without interruption
                    //modify to incorporate separate functions (not needed for this lab)
                    if(scanPosition == 180){
                        lcd_printf("COMPLETED SCAN!");
                    }
                }


    }
    // YOUR CODE HERE
    //first, try leaving this loop empty and see what happens
    //then add code for your application
    // OPTIONAL
    //test and reset command_flag if your ISR is updating it
    //for example, if the flag is 1, do something, like send a message to PuTTY or LCD, or stop a sensor scan, etc.
    //be sure to reset command_flag so you don't keep responding to an old flag

}
