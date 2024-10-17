#include "lcd.h"
#include "open_interface.h"
#include "timer.h"
#include "movement.h"

/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Chad Nelson
 * @date 06/26/2012
 */


int main (void) {
   oi_t *sensor_data = oi_alloc();
   oi_init(sensor_data);

   int sum = 0;
   int distance_mm =2000;
   int i=0;

   /**for (i=0; i<3; i++){
       move_forward(sensor_data, distance_mm);
         turn_clockwise(sensor_data, 70);
   }
   move_forward(sensor_data, distance_mm);**/

   while (sum < distance_mm) {
       oi_setWheels(250,250);
       oi_update(sensor_data);
       sum += sensor_data -> distance;
       if(sensor_data -> bumpLeft){
           move_Backward(sensor_data, 15);
           sum -= 150;
           turn_clockwise(sensor_data, 70);
           move_forward(sensor_data, 25);
           turn_counterClock(sensor_data,70);
           oi_setWheels(250,250);
       } else if(sensor_data -> bumpRight){
           move_Backward(sensor_data, 15);
           sum -= 150;
           turn_counterClock(sensor_data, 70);
           move_forward(sensor_data, 25);
           turn_clockwise(sensor_data,70);
           oi_setWheels(250,250);
       }
   }

   oi_setWheels(0,0);
   oi_free(sensor_data);
   return 0;
}
