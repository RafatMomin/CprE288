#include "lcd.h"
#include "open_interface.h"
#include "Timer.h"
#include "movement.h"
#include "cyBot_scan.h"
#include <string.h>
#include "uart-interrupt.h"
#include "ADC.h"
#include <math.h>
//struct
typedef struct
{
    int object;
    int angle;
    float distance;
    float width;

} object_info;
//prints = printToMonitor
void printToMonitor(char *words)
{
    int j = 0;
    for (j = 0; j < strlen(words); j++)
    {
        uart_sendChar(words[j]);
    }
}

//calibrate, comment out once calibrated

//int main(void){
//    timer_init();
//    lcd_init();
//    cyBOT_init_Scan(0b0111);
//    //cyBOT_SERVO_cal();
//
//    right_calibration_value = 227500;
//    left_calibration_value = 1256500;
//    int i;
//    cyBOT_Scan_t scan;
//    for(i=0;i<=180;i+=2){
//        cyBOT_Scan(i,&scan);
//    }
//    return 0;
//}
//cybot 13
//Right 332500
//Left 1267000

/**
 * main.c
 */


int main(void)
{
    oi_t *sensor_data = oi_alloc();
    oi_init(sensor_data);
    uart_interrupt_init();
    ADC_init();
    lcd_init();

    object_info objects[6] = {0};
    object_info widest = {0};

    //allows for the entirety of 5 objects to be stored with 4 elements each
    int current = 0;
    //keeps track of the current object throughout the entire program, very important
    cyBOT_init_Scan(0b0111);
    cyBOT_Scan_t scan;

    char label[40] = "\nAngle\t\tIRdata\t\tPing";
    //print = label
    char i = 0;
    //should be an int?
    for (i = 0; i < strlen(label); i++)
    {
        uart_sendChar(label[i]);
    }
    char j = 0;

    int userInput = uart_receive();
    float lastDistance = 0;
    float lastIRDistance = 0;
    float currentDistance = 0;
    int last_angle = 0;
    int first_angle = 0;
    char lookingAt = 0;
    char start = 0;
    float irData = 0;
    double irDatainCent = 0;
    double average = 0;
    double angleOffset = 0;
    float distLeft = 100;
    //double radOffset = 0;
    //double trigDist = 0;
    cyBOT_Scan(0, &scan);
    //timer_waitMillis(1000);
    char msg[90];
    double totalDistance = 0;



    if (userInput == 'm')
    {
//        turn_right(sensor_data, 90);
//            turn_right(sensor_data, -90);
//            turn_left(sensor_data, 90);
//            turn_left(sensor_data, -90);
       while(1){
//           current = 0;
//           start = 0;
//        for (i = 0; i <= 180; i += 2)
//        {
            cyBOT_Scan(90, &scan);
           currentDistance = scan.sound_dist;
//            char msg[90];
           irData = ADC_read();
//           rDatainCent = 8057.6 *pow(irData, -0.937);
//            //try to get rid of this ir stuff by the end, we dont need it
//           //printf(msg,"\n Distance: %lf",irDatainCent);
//           //cd_printf(msg);
//            timer_waitMillis(80);
//            sprintf(label, "\n\r%d\t\t%.2f\t\t%.2f", i, irData,
//                    currentDistance);
            totalDistance += currentDistance;
//            for (j = 0; j < strlen(label); j++)
//            {
                uart_sendChar(label[j]);
                sprintf(msg,"Distance: %.2f\nRaw value: %.2f\n ",currentDistance,irData);
                lcd_printf(msg);
 //           }
//            //changed to IR
//            if(irData < 800 && currentDistance > 80){
//                start = 1;
//            }
//            if (irData > 800 && currentDistance < 80 && start == 1)
//            {
//                //85 is the maximum detect distance for objects
//                lookingAt = 1;
//            }
//            else
//            {
//                lookingAt = 0;
//            }
//            //changed to IR
//            if (abs(irData - lastIRDistance) <= 200.0 && lookingAt == 1)
//            {
//                //object detected
//                if (first_angle == 0)
//                {
//                    first_angle = i;
//                }
//                //changed to IR
//            }
//            else if ((abs(irData - lastIRDistance) > 200.0 && last_angle == 0
//                    && first_angle != 0) || (lookingAt == 1 && i >= 180))
//            {
//                //moving away from an object, updates last angle
//                last_angle = i - 2;
//                objects[current].object = current;
//                objects[current].angle = ((last_angle + first_angle) / 2);
//                objects[current].distance = lastDistance;
//                //check eq
//                objects[current].width = 2.0 * 3.14 * objects[current].distance * ((last_angle - first_angle) / 360.0);
//                current++;
//                first_angle = 0;
//                last_angle = 0;
//            }
//            //changed to IR
//            lastIRDistance = irData;
//            lastDistance = currentDistance;
//        }
//
//        char printObjects[] = "\n\n\rObject#\t\tAngle\t\tDistance\tWidth";
//
//        printToMonitor(printObjects);
//        for (i = 0; i < current; i++)
//        {
//            sprintf(label, "\n\r%d\t\t%d\t\t%.2f\t\t%.2f",
//                    objects[i].object + 1,
//                    objects[i].angle,
//                    objects[i].distance,
//                    objects[i].width);
//
//            printToMonitor(label);
//
//        }
////widest is actually narrowest
//        widest = objects[0];
//        for (i = 0; i < current; i++)
//        {
//            if (objects[i].width < widest.width && objects[i].width > 3)
//            {
//                widest = objects[i];
//            }
//        }
//
//        cyBOT_Scan(widest.angle, &scan);
//
//        sprintf(label, "\n\r%d\t\t%d\t\t%.2f\t\t%.2f",
//                widest.object + 1,
//                widest.angle,
//                widest.distance,
//                widest.width);
//        printToMonitor(label);
//        distLeft = widest.distance;
//
//        //TODO ***figure out why putty is being stoopid, your previous lab didnt work which should be impossible***
//        //movement code here
//        //rotate to match the widest.angle, I already fixed it
//        //use movement.h commands to go straight at it, the code that is written should take care of navigation for us
//        //when comparing distance in the for loop use the sonar exclusively for distance.
////        timer_waitMillis(1000);
////        userInput = uart_receive();
//        angleOffset = abs(90 - (double) widest.angle);
//        //radOffset = angleOffset * 3.14 / 180;
//        //trigDist = (double)widest.distance;
//        //angleOffset = atan((cos(angleOffset) * trigDist + 15) / (sin(angleOffset) * trigDist));
//        //angleOffset = (atan((sin(radOffset) - cos(radOffset)) / 15) * trigDist) * 180 / 3.14;
//
//
//
//
//            if (widest.angle > 90)
//            {
//                //turn left
//                //angleOffset = abs(angleOffset - 90);
//                //angleOffset = asin()
//                turn_right(sensor_data, abs(angleOffset-5));
//            }
//            else if (widest.angle < 90)
//            {
//                //turn right
//                //angleOffset = abs(90 - angleOffset);
//                turn_left(sensor_data, abs(angleOffset-5));
//            }
//            oi_setWheels(0, 0);
//            //s should stop this
//            if(widest.distance>10){
//                move_forward(sensor_data, widest.distance  - 10);
//            }

       }
    }

    oi_free(sensor_data);
    return 0;
}


