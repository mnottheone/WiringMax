
/*
 * {% copyright %}
 */

#ifndef __VARIANT_H__
#define __VARIANT_H__

#include <stdint.h>
#include <unistd.h>
#include <AnalogIO.h> //for structures definitions pwm and adc description 
#include <wiring_digital.h> // for pin description and pinstate
#include "pins_arduino.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
#define LINUX_BOOTLOADER_TTY		"/dev/ttyGS0"                       // ring buffers in sysfs // will be added after TTUART file 
#define LINUX_SPIDEV			"/dev/spidev1.0"
#define LINUX_EEPROM			"/sys/bus/i2c/devices/0-0050/eeprom"
#define LINUX_ADC_FMT			"/sys/bus/iio/devices/iio:device0/in_voltage%d_raw"
#define PLATFORM_ID			0x06	// Fab D platform id
x
//#define ADC_RESOLUTION			12

//#define MAX_VARIANT_HPET_FREQ_HZ	1000

*/
extern PinDescription g_APinDescription[] ;  // from wiring_digital.h
extern uint32_t sizeof_g_APinDescription;
extern PwmDescription g_APwmDescription[] ; // from analogio.h
extern uint32_t sizeof_g_APwmDescription;
extern AdcDescription g_AdcDescription[] ;  // from analogio.h
extern uint32_t sizeof_g_AdcDescription;
extern uint32_t ardPin2DescIdx[GPIO_TOTAL];  
extern PinState g_APinState[] ;              // from wiring_digital.h
extern uint32_t sizeof_g_APinState;

//const unsigned mapUnoPinToSoC(uint8_t pin);  

//int variantPinMode(uint8_t pin, uint8_t mode);
//int variantPinModeIRQ(uint8_t pin, uint8_t mode);
//void turnOffPWM(uint8_t pin);
//void turnOnPWM(uint8_t pin);

//void variantEnableFastGpio(int pin);// not needed 

//void variantEnablePullup(uint8_t pin, int enable);




#ifdef __cplusplus
}
#endif


#endif 
