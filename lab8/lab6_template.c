///**
// * lab6_template.c
// *
// * Template file for CprE 288 Lab 6
// *
// * @author Diane Rover, 2/15/2020
// *
// */
//
//#include "Timer.h"
//#include "lcd.h"
//#include "cyBot_Scan.h"  // For scan sensors
//#include "uart.h"
//
//// Uncomment or add any include directives that are needed
//// #include "open_interface.h"
//// #include "movement.h"
//// #include "button.h"
//
//
//#warning "Possible unimplemented functions"
//#define REPLACEME 0
//
//
//int main(void) {
//	timer_init(); // Must be called before lcd_init(), which uses timer functions
//	lcd_init();
//	uart_init();
//	cyBOT_Scan_t scan;
//	cyBOT_init_Scan(0b0111);
//	// YOUR CODE HERE
//
//	char in = -1;
//	int doScan = 0;
//	int scanPos = 0;
//	while(1)
//	{
//
//	    if((UART1_FR_R & 0x10) == 0){
//	             in = uart_receive_nonblocking();
//	             lcd_printf("%c",in);
//	         }
//	    if(in != -1){
//	        if(in == 'g'){
//	            if(!doScan){
//	            doScan = 1;
//	            scanPos = 0;
//	            }
//	        }
//	        if(in == 's'){
//	            doScan = 0;
//	        }
//	    }
//	    if(doScan){
//	                    cyBOT_Scan(scanPos, &scan);
//	                    scanPos+=2;
//	                }
//
//      // YOUR CODE HERE
//
//
//	}
//
//}
