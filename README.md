![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Color_5 Click

- **CIC Prefix**  : COLOR5
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : apr 2018.

---

### Software Support

We provide a library for the Color_5 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2402/color-5-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register.
The library includes function to read the color through a red, green, and blue filter and IR data. The user can set the color of the LEDs.
The sensor has a proximity mode with which it can detect the object in front of the sensor.
The user has a function for reading light through one filter as well as reading the light through all the filters.

Key functions :

- ``` void color5_setConfiguration(uint8_t reg, uint8_t _data) ``` - Functions for configuration sensor
- ``` void color5_setLedDriver(uint8_t red, uint8_t green, uint8_t blue) ``` - Functions for setting led color
- ``` uint16_t color5_readData(uint8_t reg) ``` - Functions for read data from register
- ``` uint8_t color5_getInterrupt() ``` - Functions for proximity detect

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes driver init and configuration proximity and led driver
- Application Task - (code snippet) - Reads the color values through a red, blue, green filter and IR data.
                                      Checking that the proximity sensor detect the object.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2402/color-5-click) page.

Other mikroE Libraries used in the example:

- Conversions
- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
