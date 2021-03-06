/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "ORB.h"
#include "LED.h"
#include "super_servo.h"
#include "sensor_control.h"
#include "sensor.h"
#include "test.h"
#include "UART_control.h"
#include "UART.h"

uint8_t* global_sensor_value = NULL;

volatile uint8_t ring_buffer[MAX_LIMIT_RING_BUFFER];
volatile uint8_t tail_ring_buffer=0;
volatile uint8_t head_ring_buffer=0;
volatile bool received_data_updated=false;

volatile uint8_t serial_timeout_count = 0;
volatile bool serial_timeout = false;
volatile uint8_t count_broadcast = 0;

void load_input()
{
	read_all_sensors();	
}

void sensor_check()
{
	read_all_sensors();
}

int main (void)
{
	system_init();
	delay_init();
	LED_init();
	ORB_init();
	sensor_init();
	super_servo_init();
	
	serial_init();
	enable_super_servo();
	enable_ORB();
	enable_LED();
	enable_USART();
	
	/* Insert application code here, after the board has been initialized. */
	while(1)
	{
		sensor_check();
		serial_main_loop_1();
		 //test_ORB();
		 //load_input();
		 //test_LED();
		 //test_servos();
	}
}
