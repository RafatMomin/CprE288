#include "open_interface.h"

//move the cybot forward 1 meter
double move_forward(oi_t *sensor_data, double distance_mm)
{
    double sum = 0; // distance member in oi_t struct is type double

    oi_setWheels(300, 300); //drive the cybot forward

    while (sum < distance_mm)
    {
        oi_update(sensor_data);
        sum += sensor_data->distance; // use -> notation since pointer
        lcd_printf("Distance moved: %.2fmm", sum);
    }

    oi_setWheels(0, 0); //stop

    return sum;
}

//move the cybot backward
double move_backward(oi_t *sensor_data, double distance_mm)
{
    double sum = 0; // keep track of cybot distance

    oi_setWheels(-300, -300); //move backward

    while (sum > -1 * distance_mm)
    {
        oi_update(sensor_data);
        sum += sensor_data->distance; // use -> notation since pointer
        lcd_printf("Distance moved: %.2fmm", sum);
    }

    oi_setWheels(0, 0); //stop

    return sum;
}

//turn right
double turn_right(oi_t *sensor, double degrees)
{
    char data[50];
    oi_setWheels(-100, 100);
    double sum = 0;
    while (sum > degrees * -1)
    {
        oi_update(sensor);
        sum += sensor->angle;
        lcd_printf("Angles(right): %.2f\n", sum);
//        sprintf(data, "Angles(right): %.2f/%.2f\n", sum, degrees);
//        cyBot_sendString(data);
    }
    return sum;
}

//turn left
double turn_left(oi_t *sensor, double degrees)
{
    char data[50];
    oi_setWheels(100, -100);
    double sum = 0;
    while (sum < degrees)
    {
        oi_update(sensor);
        sum += sensor->angle;
        lcd_printf("Angles(left): %.2f\n", sum);
//        sprintf(data, "Angles(left): %.2f/%.2f\n", sum,degrees);
//        cyBot_sendString(data);
    }
    return sum;
}

//move the cybot forward while accounting for obstacles
double move_forward_obj(oi_t *sensor_data, double distance_mm)
{
    double sum = 0; // distance member in oi_t struct is type double

    oi_setWheels(300, 300); //move forward

    while (sum < distance_mm)
    {
        oi_update(sensor_data);
        //Check bumpers
        if (sensor_data->bumpLeft)
        {
            oi_setWheels(0, 0);
            //back up 15cm
            //90 degrees right then 25 cm
            //turn left 90, keep going
            move_backward(&sensor_data, 150);
            turn_right(&sensor_data, 90);
            move_forward(&sensor_data, 250);
            turn_left(&sensor_data, 90);
        }
        if (sensor_data->bumpRight)
        {
            oi_setWheels(0, 0);
            //back up 15cm
            //90 degrees left then 25 cm
            //turn right 90, keep going
            move_backward(&sensor_data, 150);
            turn_left(&sensor_data, 90);
            move_forward(&sensor_data, 250);
            turn_right(&sensor_data, 90);
        }
        oi_setWheels(300, 300);
        sum += sensor_data->distance; // use -> notation since pointer
        lcd_printf("Distance moved: %.2fmm", sum);
    }

    oi_setWheels(0, 0); //stop

    return sum;
}
