/* Copyright 2019 Biacco42
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "prac.h"
#include "print.h"
#include "analog.h" 

#define analog7 0x07             // PF7/ADC7
#define analog6 0x06             // PF6/ADC6
#define analog5 0x05             // PF5/ADC5
#define analog4 0x04             // PF4/ADC4
#define analog3 0x03             // PF7/ADC7
#define analog2 0x02             // PF6/ADC6
#define analog1 0x01             // PF5/ADC5
#define analog0 0x00             // PF4/ADC4

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
debug_enable = true;
	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	led_set_user(usb_led);
}


void pointing_device_init(){
debug_enable = true;
dprintf("init\n");
}

void pointing_device_task(){
debug_enable = true;
 dprintf("%d %d %d %d %d %d %d %d\n",  adc_read(analog0), adc_read(analog1), adc_read(analog2), adc_read(analog3)
 ,  adc_read(analog4), adc_read(analog5), adc_read(analog6), adc_read(analog7));
}

