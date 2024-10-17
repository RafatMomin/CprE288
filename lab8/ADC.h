/*
 * ADC.h
 *
 *  Created on: Mar 24, 2024
 *      Author: mcurrier
 */

#ifndef ADC_H_
#define ADC_H_
#include <inc/tm4c123gh6pm.h>
#include <stdint.h>
void ADC_init(void);
uint32_t ADC_read(void);

#endif /* ADC_H_ */
