#include "Timer.h"
#include "lcd.h"

#define LCD_WIDTH 20

// Function to print a restricted portion of the text on the LCD
static void printRestrict(char* str, int space) {
    int len = strlen(str);
    int i;
    int j;
    for(i = 0; i < space; i++) {
        if(i < len)
            lcd_putc(str[i]);
        else
            lcd_putc(' '); // Fill the rest of the line with spaces if the text is shorter than the remaining space
    }
}

int main(void) {
    timer_init(); // Initialize Timer
    lcd_init();   // Initialize the LCD screen and clear the screen

    char* text = "Microcontrollers are lots of fun!";
    int textLength = strlen(text);
    char displayText[LCD_WIDTH + 1]; // Buffer to hold the text to be displayed
    int i;
    int j;
    int k;
    while(1) {
        for(i = 0; i < textLength + LCD_WIDTH; i++) {
            int textStart = i - LCD_WIDTH; // Calculate the starting index of the text to be displayed
            int textEnd = i; // Calculate the ending index of the text to be displayed

            // Clear the buffer
            memset(displayText, ' ', LCD_WIDTH);
            displayText[LCD_WIDTH] = '\0';

            // Copy the relevant portion of text to the display buffer
            for(j = textStart, k = 0; j < textEnd; j++, k++) {
                if(j >= 0 && j < textLength) {
                    displayText[k] = text[j];
                }
            }

            // Print the text to the LCD
            lcd_clear(); // Clear the LCD to prevent remnants of previous text
            lcd_setCursorPos(0, 0); // Set cursor to the first line
            printRestrict(displayText, LCD_WIDTH); // Print the text on the LCD

            timer_waitMillis(300); // Wait for 300 milliseconds
        }
    }

    return 0;
}
