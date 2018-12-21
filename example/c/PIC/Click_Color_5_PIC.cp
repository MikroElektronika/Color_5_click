#line 1 "D:/Clicks_git/FULL_CLICK/Color_5_click/SW/example/c/PIC/Click_Color_5_PIC.c"
#line 1 "d:/clicks_git/full_click/color_5_click/sw/example/c/pic/click_color_5_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 1 "d:/clicks_git/full_click/color_5_click/sw/example/c/pic/click_color_5_config.h"
#line 1 "d:/clicks_git/full_click/color_5_click/sw/example/c/pic/click_color_5_types.h"
#line 14 "d:/clicks_git/full_click/color_5_click/sw/example/c/pic/click_color_5_config.h"
const uint32_t _COLOR5_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"
#line 59 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
extern const uint8_t _COLOR5_REG_RGB_SENSOR_CTRL;
extern const uint8_t _COLOR5_REG_MANUAL_TIMING_MSB;
extern const uint8_t _COLOR5_REG_MANUAL_TIMING_LSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_RED_MSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_RED_LSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_GREEN_MSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_GREEN_LSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_BLUE_MSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_BLUE_LSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_IR_MSB;
extern const uint8_t _COLOR5_REG_OUT_DATA_IR_LSB;
extern const uint8_t _COLOR5_REG_PROX_SENSOR_CTRL_1;
extern const uint8_t _COLOR5_REG_PROX_SENSOR_CTRL_2;
extern const uint8_t _COLOR5_REG_PROX_THRESHOLD;
extern const uint8_t _COLOR5_REG_3_LED_DRIVE_CTRL_1;
extern const uint8_t _COLOR5_REG_3_LED_DRIVE_CTRL_2;
extern const uint8_t _COLOR5_REG_MONITOR;


extern const uint8_t _COLOR5_CFG_SENSOR_RESET;
extern const uint8_t _COLOR5_CFG_SLEEP_MODE;
extern const uint8_t _COLOR5_CFG_REGISTER_RESET;
extern const uint8_t _COLOR5_CFG_HIGH_GAIN;
extern const uint8_t _COLOR5_CFG_LOW_GAIN;
extern const uint8_t _COLOR5_CFG_FIXED_TIME_MODE;
extern const uint8_t _COLOR5_CFG_MANUAL_SETTINGS_MODE;
extern const uint8_t _COLOR5_CFG_INTEGRATION_TIME_32us;
extern const uint8_t _COLOR5_CFG_INTEGRATION_TIME_5ms;
extern const uint8_t _COLOR5_CFG_INTEGRATION_TIME_8_2ms;
extern const uint8_t _COLOR5_CFG_INTEGRATION_TIME_65_5ms;


extern const uint8_t _COLOR5_LED_DRIVER_RESET;
extern const uint8_t _COLOR5_LED_DRIVER_SLEEP;
extern const uint8_t _COLOR5_LED_DRIVER_DC_MODE;
extern const uint8_t _COLOR5_LED_DRIVER_1_10_MODE;

extern const uint8_t _COLOR5_RED_CURRENT_0mA;
extern const uint8_t _COLOR5_GREEN_CURRENT_0mA;
extern const uint8_t _COLOR5_BLUE_CURRENT_0mA;
extern const uint8_t _COLOR5_RED_CURRENT_8mA;
extern const uint8_t _COLOR5_RED_CURRENT_16mA;
extern const uint8_t _COLOR5_RED_CURRENT_32mA;
extern const uint8_t _COLOR5_GREEN_CURRENT_8mA;
extern const uint8_t _COLOR5_GREEN_CURRENT_16mA;
extern const uint8_t _COLOR5_GREEN_CURRENT_32mA;
extern const uint8_t _COLOR5_BLUE_CURRENT_8mA;
extern const uint8_t _COLOR5_BLUE_CURRENT_16mA;
extern const uint8_t _COLOR5_BLUE_CURRENT_32mA;


extern const uint8_t _COLOR5_PROX_SENSOR_RESET;
extern const uint8_t _COLOR5_PROX_SENSOR_SLEEP;

extern const uint8_t _COLOR5_PROX_RED_LED_CURRENT_64mA;
extern const uint8_t _COLOR5_PROX_RED_LED_CURRENT_32mA;
extern const uint8_t _COLOR5_PROX_RED_LED_CURRENT_16mA;
extern const uint8_t _COLOR5_PROX_RED_LED_CURRENT_8mA;
extern const uint8_t _COLOR5_PROX_DURATION_524ms;
extern const uint8_t _COLOR5_PROX_DURATION_262ms;
extern const uint8_t _COLOR5_PROX_DURATION_131ms;
extern const uint8_t _COLOR5_PROX_DURATION_64ms;
extern const uint8_t _COLOR5_PROX_PULSES_24pulse;
extern const uint8_t _COLOR5_PROX_PULSES_12pulse;
extern const uint8_t _COLOR5_PROX_PULSES_6pulse;
extern const uint8_t _COLOR5_PROX_PULSES_3pulse;

extern const uint8_t _COLOR5_DEF_PROX_THRESHOLD;
#line 141 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
void color5_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 158 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
uint16_t color5_readData(uint8_t reg);
#line 168 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
uint8_t color5_readByte(uint8_t reg);
#line 181 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
void color5_readAllData(uint16_t *data_buffer);
#line 217 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
void color5_setConfiguration(uint8_t reg, uint8_t _data);
#line 232 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
void color5_setLedDriver(uint8_t red, uint8_t green, uint8_t blue);
#line 239 "d:/clicks_git/full_click/color_5_click/sw/library/__color5_driver.h"
uint8_t color5_getInterrupt();
#line 31 "D:/Clicks_git/FULL_CLICK/Color_5_click/SW/example/c/PIC/Click_Color_5_PIC.c"
uint16_t RED_Data;
uint16_t BLUE_Data;
uint16_t GREEN_Data;
uint16_t IR_Data;

char dataTxt[ 50 ];


void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
 mikrobus_i2cInit( _MIKROBUS1, &_COLOR5_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART, 9600 );
 mikrobus_logWrite("--- System init ---", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 color5_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x2A );

 color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_SENSOR_RESET | _COLOR5_PROX_RED_LED_CURRENT_64mA);
 color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_2, _COLOR5_PROX_DURATION_64ms | _COLOR5_PROX_PULSES_3pulse );
 color5_setConfiguration(_COLOR5_REG_PROX_THRESHOLD, _COLOR5_DEF_PROX_THRESHOLD );
 color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_RED_LED_CURRENT_64mA);

 color5_setLedDriver(_COLOR5_RED_CURRENT_0mA, _COLOR5_GREEN_CURRENT_0mA, _COLOR5_BLUE_CURRENT_32mA);
}

void applicationTask()
{

 color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL,_COLOR5_CFG_SENSOR_RESET | _COLOR5_CFG_MANUAL_SETTINGS_MODE );
 color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL, _COLOR5_CFG_LOW_GAIN | _COLOR5_CFG_MANUAL_SETTINGS_MODE );

 RED_Data = color5_readData( _COLOR5_REG_OUT_DATA_RED_MSB );
 IntToStr( RED_Data, dataTxt );
 mikrobus_logWrite( "RED data : ", _LOG_TEXT );
 mikrobus_logWrite( dataTxt, _LOG_TEXT );
 mikrobus_logWrite( " nm", _LOG_LINE );

 GREEN_Data = color5_readData( _COLOR5_REG_OUT_DATA_GREEN_MSB );
 IntToStr( GREEN_Data, dataTxt );
 mikrobus_logWrite( "GREEN data : ", _LOG_TEXT );
 mikrobus_logWrite( dataTxt, _LOG_TEXT );
 mikrobus_logWrite( " nm", _LOG_LINE );

 BLUE_Data = color5_readData( _COLOR5_REG_OUT_DATA_BLUE_MSB );
 IntToStr( BLUE_Data, dataTxt );
 mikrobus_logWrite( "BLUE data : ", _LOG_TEXT );
 mikrobus_logWrite( dataTxt, _LOG_TEXT );
 mikrobus_logWrite( " nm", _LOG_LINE );

 IR_Data = color5_readData( _COLOR5_REG_OUT_DATA_IR_MSB );
 IntToStr( IR_Data, dataTxt );
 mikrobus_logWrite( "IR data : ", _LOG_TEXT );
 mikrobus_logWrite( dataTxt, _LOG_TEXT );
 mikrobus_logWrite( " nm", _LOG_LINE );

 mikrobus_logWrite("---------------\r\n", _LOG_LINE);


 if (color5_getInterrupt() == 1)
 {
 mikrobus_logWrite("Proximity detect", _LOG_LINE);
 }
 Delay_ms( 500 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
