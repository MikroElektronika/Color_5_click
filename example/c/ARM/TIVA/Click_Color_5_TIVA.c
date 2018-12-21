/*
Example for Color_5 Click

    Date          : apr 2018.
    Author        : Katarina Perendic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes driver init and configuration proximity and led driver
- Application Task - (code snippet) - Reads the color values through a red, blue, green filter and IR data.
                                      Checking that the proximity sensor detect the object.

*/

#include "Click_Color_5_types.h"
#include "Click_Color_5_config.h"

uint16_t RED_Data;
uint16_t BLUE_Data;
uint16_t GREEN_Data;
uint16_t IR_Data;

char dataTxt[ 50 ];


void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_COLOR5_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite("--- System init ---", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    color5_i2cDriverInit( (T_COLOR5_P)&_MIKROBUS1_GPIO, (T_COLOR5_P)&_MIKROBUS1_I2C, 0x2A );
    // Proximity init
    color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_SENSOR_RESET | _COLOR5_PROX_RED_LED_CURRENT_64mA);
    color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_2, _COLOR5_PROX_DURATION_64ms | _COLOR5_PROX_PULSES_3pulse );
    color5_setConfiguration(_COLOR5_REG_PROX_THRESHOLD, _COLOR5_DEF_PROX_THRESHOLD );
    color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_RED_LED_CURRENT_64mA);
    // LED driver init
    color5_setLedDriver(_COLOR5_RED_CURRENT_0mA, _COLOR5_GREEN_CURRENT_0mA, _COLOR5_BLUE_CURRENT_32mA);
}

void applicationTask()
{
    // Color init
    color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL,_COLOR5_CFG_SENSOR_RESET | _COLOR5_CFG_MANUAL_SETTINGS_MODE );
    color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL, _COLOR5_CFG_LOW_GAIN  | _COLOR5_CFG_MANUAL_SETTINGS_MODE );

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