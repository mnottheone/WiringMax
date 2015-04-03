/* copyright */
#include <sysfs.h>
//#include <trace.h> can be included also , since in this file no change is required 
#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////// MB MAX ///////////////////////////////

/*
"Description                 | Name                  | Pin|   Linux GPIO #   "
                                                          | >=3.18 | <=3.17 |  
"----------------------------+-----------------------+-----+-----------------"
 Ground                      | GND                   | 1  |        |     |
Ground                       | GND                   | 2  |        |     |
+5V Power                    | +5V                   | 3  |        |     |
+3.3V Power                  | +3V3                  | 4  |        |     |
SPI Chip Select              | GPIO_SPI_CS#          | 5  | 476    | 220 |
GPIO_UART1_TXD               | UART1_TXD             | 6  | 481    | 225 |
Master In / Slave Out (MISO) | GPIO_SPI_MISO         | 7  | 477    | 221 |
GPIO_UART1_RXD               | UART1_RXD             | 8  | 480    | 224 |
Master Out / Slave In        | GPIO_SPI_MOSI         | 9  | 478    | 222 |
CTS / GPIO                   | GPIO_UART1_CTS        | 10 | 483    | 227 |
SPI Clock                    | GPIO_SPI_CLK          | 11 | 479    | 223 |
RTS / GPIO                   | GPIO_UART1_RTS        | 12 | 484    | 226 | 
Clock / GPIO                 | GPIO_I2C_SCL (I2C #5) | 13 | 499    | 243 |
Clock / GPIO                 | GPIO_I2S_CLK          | 14 | 472    | 216 |
Data / GPIO                  | GPIO_I2C_SDA (I2C #5) | 15 | 498    | 242 |
Frame / GPIO                 | GPIO_I2S_FRM          | 16 | 473    | 217 |
UART Transmit                | GPIO / GPIO_UART2_TXD | 17 | 485    | 229 |
Data Out / GPIO              | GPIO_I2S_DO           | 18 | 475    | 219 |
UART Receive / GPIO i        | GPIO_UART2_RXD        | 19 | 484    | 228 |
Data In / GPIO               | GPIO_I2S_DI           | 20 | 474    | 218 |
GPIO / Wakeup                | GPIO_S5_0             | 21 | 338    |  82 |
PWM / GPIO                   | GPIO_PWM0             | 22 | 504    | 248 |
GPIO / Wakeup                | GPIO_S5_1             | 23 | 339    |  83 |
PWM / GPIO                   | GPIO_PWM1             | 24 | 505    | 249 |
GPIO / Wakeup                | GPIO_S5_4             | 25 | 340    |  84 |
Timer / GPIO                 | GPIO_IBL_8254         | 26 | 464    | 208 |
--------------------------------------------------------------------------"*/
// TODO Add gpioID for linux <=3.17 
// SORTED ACCORDING BOARD PIN NUMBER //
PinDescription g_APinDescription[]=
{
//    gpiolib	alias	fastid	ardid	Initial	FixdSt	ptMuxDesc,	MuxCount	type		   Handle	iAlt	pAlt  //
	{476,	NONE,	NONE,	10,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
        {481,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{477,	NONE,	NONE,	12,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{480,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{478,	NONE,	NONE,	11,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{483,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{479,	NONE,	NONE,	13,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{484,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{499,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{472,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{498,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{473,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{485,	NONE,	NONE,	19,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{475,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{484,	NONE,	NONE,	18,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{474,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{338,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{504,	NONE,	NONE,	3,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{339,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{505,	NONE,	NONE,	9,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{340,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL},
	{464,	NONE,	NONE,	NONE,	LOW,	NONE,	NULL,		NONE,		FN_GPIO_OVERDRAIN	-1,	0,	NULL}
};

uint32_t sizeof_g_APinDescription;

uint32_t ardPin2DescIdx[GPIO_TOTAL]; 

// Sorted by Linux PWM ID
PwmDescription g_APwmDescription[] = {

	{ 0,	9,	-1,	-1 },
	{ 1,	3,	-1,	-1 },
};
uint32_t sizeof_g_APwmDescription;

// Sorted Arduino Pin ID// + signifies pins has been used // * signifies used with same property as in arduino 
PinState g_APinState[]=
{
	/* uCurrentPwm	uCurrentInput	uCurrentAdc			*/
	{ 0,		1,		0 },	/* 0			*/
	{ 0,		1,		0 },	/* 1			*/
	{ 0,		1,		0 },	/* 2			*/
	{ 0,		1,		0 },	/* 3  - PWM*	+	*/
	{ 0,		1,		0 },	/* 4 			*/
	{ 0,		1,		0 },	/* 5  - PWM 		*/
	{ 0,		1,		0 },	/* 6  - PWM		*/
	{ 0,		1,		0 },	/* 7 			*/
	{ 0,		1,		0 },	/* 8 			*/
	{ 0,		1,		0 },	/* 9  - PWM*	+	*/
	{ 0,		1,		0 },	/* 10 - PWM	+	*/
	{ 0,		1,		0 },	/* 11 - PMW	+	*/
	{ 0,		1,		0 },	/* 12		+	*/
	{ 0,		1,		0 },	/* 13		+	*/
	{ 0,		1,		0 },	/* 14 - ADC		*/
	{ 0,		1,		0 },	/* 15 - ADC		*/
	{ 0,		1,		0 },	/* 16 - ADC		*/
	{ 0,		1,		0 },	/* 17 - ADC		*/
	{ 0,		1,		0 },	/* 18 - ADC	+	*/
	{ 0,		1,		0 },	/* 19 - ADC	+	*/
};
uint32_t sizeof_g_APinState;



#ifdef __cplusplus
}
#endif
// assumning I have sysfs , analogio, digital_wiring and trace with required which we really have (almost)
//TODO RING BUFFERS FOR so, s4, s5 to be added // 
//
/*
int variantPinModeIRQ(uint8_t pin, uint8_t mode)
{
	return 0;
}
 
void turnOnPWM(uint8_t pin)
{
	uint32_t ret = 0;
	int gpio = 0;

	if (pin >= GPIO_TOTAL){
		trace_error("%s: invalid pin%u", __func__, pin);
		return;
	}

	// Mark PWM enabled on pin 
	g_APinState[pin].uCurrentPwm = 1;

	// Reflect actual muxing change
	ret = muxSelectDigitalPin(pin);
	if (ret) {
		trace_error("%s: can't set mux for pin%d",
			    __func__, pin);
	}

	g_APinState[pin].uCurrentAdc = 0;

	// Set strong drive and output direction 
	gpio = g_APinDescription[ardPin2DescIdx[pin]].ulGPIOId;
	ret = sysfsGpioSetDrive(gpio, GPIO_DRIVE_STRONG);
	if (ret) {
		trace_error("%s: can't set strong drive for pin%d", __func__,
			    pin);
		return;
	}
	ret = sysfsGpioDirection(gpio, 1, 1);
	if (ret) {
		trace_error("%s: can't set directon for pin%d", __func__, pin);
		return;
	}

	return;
}

void turnOffPWM(uint8_t pin)
{
	int handle = 0;
	PinDescription *p = NULL;

	if (pin >= GPIO_TOTAL){
		trace_error("%s: invalid pin%u", __func__, pin);
		return;
	}

	// Scan mappings
	p = &g_APinDescription[ardPin2DescIdx[pin]];
	pin2alternate(&p);

	if(p->ulArduinoId == pin) {
		handle = pin2pwmhandle_enable(pin);
		if ((int)PIN_EINVAL == handle) {
			trace_error("%s: bad handle for pin%u",
				    __func__, pin);
			return;
		}
		if (sysfsPwmDisable(handle)) {
			trace_error("%s: couldn't disable pwm "
				    "on pin%u", __func__, pin);
			return;
		}

		// Mark PWM disabled on pin 
		g_APinState[pin].uCurrentPwm = 0;

		return;
}*/

void init( int argc, char * argv[] )
{
	/*if(argc > 1)
		if(Serial.init_tty(argv[1]) != 0)		// will be intialised only when we have TTUART and  buffer ready 
			return;
	if(argc > 2)
		if(Serial1.init_tty(argv[2]) != 0)		
			return;
	if(argc > 3)
		if(Serial2.init_tty(argv[3]) != 0)
			return;
*/
	sizeof_g_APinDescription = sizeof(g_APinDescription)/sizeof(struct _PinDescription);
	pinInit(); // It is in wiring_digital 
	/*  changes in pin description required 
	*   pin type is automatically handled (need to conform, once more -> checkout lure file )
	*   can remove mux information 
	**  pinInit();
	*   generate handles 
	*   intialize ardId2DescIdx[] ( not required intially, since directly using calamari lure ids)
	*/
	
	
	//sizeof_g_APwmDescription = sizeof(g_APwmDescription)/sizeof(struct _PwmDescription);
	//pwmInit();
	//sizeof_g_AdcDescription = sizeof(g_AdcDescription)/sizeof(struct _AdcDescription);
	//adcInit(); // need to work on it wiring_analog
	sizeof_g_APinState = sizeof(g_APinState)/sizeof(struct _PinState);
}

