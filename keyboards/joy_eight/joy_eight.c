/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "joy_eight.h"
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


static int x_neutral, y_neutral;
static report_mouse_t mouseReport = {};


void matrix_init_kb(void) {
debug_enable = true;
	matrix_init_user();
}

void matrix_scan_kb(void) {
	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	led_set_user(usb_led);
}


void pointing_device_init(){
debug_enable = true;
 x_neutral = adc_read(analog4);
 y_neutral = adc_read(analog5);
dprintf("init\n");
}

void pointing_device_task(){
debug_enable = true;

mouseReport.x = 0;
mouseReport.y = 0;


if (((adc_read(analog4) - x_neutral) * (adc_read(analog4) - x_neutral) 
+ (adc_read(analog5) - y_neutral) * (adc_read(analog5) - y_neutral)) < 3){
host_mouse_send(&mouseReport);
return;
}


float x_temp = (adc_read(analog4) - x_neutral) / 4.;
float y_temp = (adc_read(analog5) - y_neutral) / 4.;

mouseReport.x = (120. * sin(3.14 * x_temp / 128. / 2.) / 2.); 
mouseReport.y = (120. * sin(3.14 * y_temp / 128. / 2.) / 2.);
dprintf("%d %d\n",mouseReport.x,mouseReport.y);
host_mouse_send(&mouseReport);
}

