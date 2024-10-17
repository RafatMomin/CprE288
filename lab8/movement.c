#include "open_interface.h"
#include "movement.h"
#include "Timer.h"
#include "lcd.h"

double move_forward(oi_t*sensor_data, double distance_mm){
  oi_setWheels(0,0);
  double sum = 0;
  oi_setWheels(100,100); // set... fast
  while(sum < distance_mm){//go untill distance
      oi_setWheels(100,100);

      if( sensor_data -> bumpRight){
          oi_update(sensor_data);
          move_backward(sensor_data, 150);
          turn_right(sensor_data, 90);
          move_forward(sensor_data, 150);
          turn_left(sensor_data,90);

      }

      if(sensor_data -> bumpLeft){
          oi_update(sensor_data);
               move_backward(sensor_data, 150);
               turn_left(sensor_data, 90);
                move_forward(sensor_data, 150);
                turn_right(sensor_data, 90);

            }
      oi_update(sensor_data);
      sum += sensor_data -> distance; // this is pointer


  }
  oi_setWheels(0,0); // STOP!
  return(sum); // just becuase double ya know
}

double move_backward(oi_t*sensor_data, double distance_mm){
  oi_setWheels(0,0);
  double sum = 0;
  oi_setWheels(-100,-100); // set... fast
  while(sum > -1*distance_mm){//go untill distance
      oi_update(sensor_data);
      sum += sensor_data -> distance; // this is pointer

  }
  oi_setWheels(0,0); // STOP!
  return(sum); // just becuase double ya know
}

double turn_right(oi_t*sensor_data, double angle_deg){
  oi_setWheels(0,0);
  double sum = 0;
  oi_setWheels(100,-100); // set... fast
  while(sum < angle_deg){//go untill distance
      oi_update(sensor_data);
      sum += sensor_data -> angle; // this is pointer

  }
  oi_setWheels(0,0); // STOP!
  return(sum); // just becuase double ya know
}

double turn_left(oi_t*sensor_data, double angle_deg){
  oi_setWheels(0,0);
  double sum = 0;
  oi_setWheels(-100,100); // set... fast
  while(sum < angle_deg){//go untill distance
      oi_update(sensor_data);
      sum -= sensor_data -> angle; // this is pointer

  }
  oi_setWheels(0,0); // STOP!
  return(sum); // just becuase double ya know
}
