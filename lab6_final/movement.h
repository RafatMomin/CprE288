/*
 * movement.h
 *
 *  Created on: Jan 31, 2024
 *      Author: bellas23
 */
#include "open_interface.h"

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

double move_forward_obj(oi_t *sensor_data, double distance_mm);
double move_forward(oi_t *sensor_data, double distance_mm);
double move_backward(oi_t *sensor_data, double distance_mm);
double turn_right(oi_t *sensor, double degrees);
double turn_left(oi_t *sensor, double degrees);

#endif /* MOVEMENT_H_ */
