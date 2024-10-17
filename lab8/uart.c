/*
 *
 *   uart.c
 *
 *
 *
 *
 *
 *   @author
 *   @date


#include "uart_extra_help.h"

volatile char uart_data; //variable that holds the copied data
volatile char flag; //variable that holds the copied data

void uart_init(int baud)
{
    SYSCTL_RCGCGPIO_R |= 0b00000010;      // enable clock GPIOB (page 340)
    SYSCTL_RCGCUART_R |= 0b00000010;      // enable clock UART1 (page 344)
    timer_waitMillis(1);
    GPIO_PORTB_AFSEL_R |= 0b00000011;// sets PB0 and PB1 as peripherals (page 671)
    GPIO_PORTB_PCTL_R |= 0x00000011; // pmc0 and pmc1       (page 688)  also refer to page 650
    GPIO_PORTB_DEN_R |= 0b00000011;        // enables pb0 and pb1
    GPIO_PORTB_DIR_R &= 0b11111100;        // sets pb0 as output, pb1 as input
    GPIO_PORTB_DIR_R |= ~(0b11111110);

    //compute baud values [UART clock= 16 MHz]
    double fbrd;
    int ibrd;
    double brd;


    brd = 16000000.0 / (16.0 * baud);
    ibrd = (int)(brd);
    fbrd = ((brd - ibrd) * 64) + .5;

    UART1_CTL_R &= 0xFFFE;      // disable UART1 (page 918)
    UART1_IBRD_R = ibrd;        // write integer portion of BRD to IBRD
    UART1_FBRD_R = fbrd;   // write fractional portion of BRD to FBRD
    UART1_LCRH_R = 0x60; // write serial communication parameters (page 916) * 8bit and no parity
    UART1_CC_R = 0x0;     // use system clock as clock source (page 939)
    UART1_CTL_R |= 0x0001;        // enable UART1

}

void uart_sendChar(char data)
{
    while (UART1_FR_R & 0x20)
    {
    }
        UART1_DR_R = data;

}

char uart_receive(void)
{
   // uint32_t ret;
    char data;
    while (UART1_FR_R & 0x10)
    {
    }

        data = (char)(UART1_DR_R & 0xFF);

        return data;

}

void uart_sendStr(const char *data)
{
    while(*data != '\0')
        {
            uart_sendChar(*data);
            data++;
        }
}

void uart_interrupt_init()
{
    // Enable interrupts for receiving bytes through UART1
    UART1_IM_R |= 0x0010; //enable interrupt on receive - page 924

    // Find the NVIC enable register and bit responsible for UART1 in table 2-9
    // Note: NVIC register descriptions are found in chapter 3.4
    NVIC_EN0_R |= 0x0040; //enable uart1 interrupts - page 104

    // Find the vector number of UART1 in table 2-9 ! UART1 is 22 from vector number page 104
    IntRegister(INT_UART1, uart_interrupt_handler); //give the microcontroller the address of our interrupt handler - page 104 22 is the vector number

}

void uart_interrupt_handler()
{
// STEP1: Check the Masked Interrup Status

    // IF RECIEVE
    flag = 1;
    if (UART1_MIS_R & 0X10)
    {
        uart_data = UART1_DR_R;
        UART1_ICR_R = UART1_ICR_R | 0X10;
    }




//STEP2:  Copy the data


//STEP3:  Clear the interrup

}
*/
