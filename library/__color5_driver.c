/*
    __color5_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__color5_driver.h"
#include "__color5_hal.c"

/* ------------------------------------------------------------------- MACROS */
// Register map
const uint8_t _COLOR5_REG_RGB_SENSOR_CTRL     = 0x00;
const uint8_t _COLOR5_REG_MANUAL_TIMING_MSB   = 0x01;
const uint8_t _COLOR5_REG_MANUAL_TIMING_LSB   = 0x02;
const uint8_t _COLOR5_REG_OUT_DATA_RED_MSB    = 0x03;
const uint8_t _COLOR5_REG_OUT_DATA_RED_LSB    = 0x04;
const uint8_t _COLOR5_REG_OUT_DATA_GREEN_MSB  = 0x05;
const uint8_t _COLOR5_REG_OUT_DATA_GREEN_LSB  = 0x06;
const uint8_t _COLOR5_REG_OUT_DATA_BLUE_MSB   = 0x07;
const uint8_t _COLOR5_REG_OUT_DATA_BLUE_LSB   = 0x08;
const uint8_t _COLOR5_REG_OUT_DATA_IR_MSB     = 0x09;
const uint8_t _COLOR5_REG_OUT_DATA_IR_LSB     = 0x0A;
const uint8_t _COLOR5_REG_PROX_SENSOR_CTRL_1  = 0x0B;
const uint8_t _COLOR5_REG_PROX_SENSOR_CTRL_2  = 0x0C;
const uint8_t _COLOR5_REG_PROX_THRESHOLD      = 0x0D;
const uint8_t _COLOR5_REG_3_LED_DRIVE_CTRL_1  = 0x0E;
const uint8_t _COLOR5_REG_3_LED_DRIVE_CTRL_2  = 0x0F;
const uint8_t _COLOR5_REG_MONITOR             = 0x10;

// Configuration color register
const uint8_t _COLOR5_CFG_SENSOR_RESET            = 0x80;
const uint8_t _COLOR5_CFG_SLEEP_MODE              = 0x40;
const uint8_t _COLOR5_CFG_REGISTER_RESET          = 0x10;
const uint8_t _COLOR5_CFG_HIGH_GAIN               = 0x00;
const uint8_t _COLOR5_CFG_LOW_GAIN                = 0x08;
const uint8_t _COLOR5_CFG_FIXED_TIME_MODE         = 0x00;
const uint8_t _COLOR5_CFG_MANUAL_SETTINGS_MODE    = 0x04;
const uint8_t _COLOR5_CFG_INTEGRATION_TIME_32us   = 0x00;
const uint8_t _COLOR5_CFG_INTEGRATION_TIME_5ms    = 0x01;
const uint8_t _COLOR5_CFG_INTEGRATION_TIME_8_2ms  = 0x02;
const uint8_t _COLOR5_CFG_INTEGRATION_TIME_65_5ms = 0x03;

// configuration LED Driver register
const uint8_t _COLOR5_LED_DRIVER_RESET     = 0x80;
const uint8_t _COLOR5_LED_DRIVER_SLEEP     = 0x40;
const uint8_t _COLOR5_LED_DRIVER_DC_MODE   = 0x20;
const uint8_t _COLOR5_LED_DRIVER_1_10_MODE = 0x10;

const uint8_t _COLOR5_RED_CURRENT_0mA    = 0x00;
const uint8_t _COLOR5_RED_CURRENT_8mA    = 0x01;
const uint8_t _COLOR5_RED_CURRENT_16mA   = 0x02;
const uint8_t _COLOR5_RED_CURRENT_32mA   = 0x04;
const uint8_t _COLOR5_GREEN_CURRENT_0mA  = 0x00;
const uint8_t _COLOR5_GREEN_CURRENT_8mA  = 0x01;
const uint8_t _COLOR5_GREEN_CURRENT_16mA = 0x02;
const uint8_t _COLOR5_GREEN_CURRENT_32mA = 0x04;
const uint8_t _COLOR5_BLUE_CURRENT_0mA   = 0x00;
const uint8_t _COLOR5_BLUE_CURRENT_8mA   = 0x01;
const uint8_t _COLOR5_BLUE_CURRENT_16mA  = 0x02;
const uint8_t _COLOR5_BLUE_CURRENT_32mA  = 0x04;

// configuration proximity register
const uint8_t _COLOR5_PROX_SENSOR_RESET = 0x80;
const uint8_t _COLOR5_PROX_SENSOR_SLEEP = 0x40;

const uint8_t _COLOR5_PROX_RED_LED_CURRENT_64mA = 0x08;
const uint8_t _COLOR5_PROX_RED_LED_CURRENT_32mA = 0x04;
const uint8_t _COLOR5_PROX_RED_LED_CURRENT_16mA = 0x20;
const uint8_t _COLOR5_PROX_RED_LED_CURRENT_8mA  = 0x10;
const uint8_t _COLOR5_PROX_DURATION_524ms       = 0x80;
const uint8_t _COLOR5_PROX_DURATION_262ms       = 0x40;
const uint8_t _COLOR5_PROX_DURATION_131ms       = 0x20;
const uint8_t _COLOR5_PROX_DURATION_64ms        = 0x10;
const uint8_t _COLOR5_PROX_PULSES_24pulse       = 0x08;
const uint8_t _COLOR5_PROX_PULSES_12pulse       = 0x04;
const uint8_t _COLOR5_PROX_PULSES_6pulse        = 0x02;
const uint8_t _COLOR5_PROX_PULSES_3pulse        = 0x01;

const uint8_t _COLOR5_DEF_PROX_THRESHOLD = 0x10;


/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __COLOR5_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __COLOR5_DRV_SPI__

void color5_spiDriverInit(T_COLOR5_P gpioObj, T_COLOR5_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __COLOR5_DRV_I2C__

void color5_i2cDriverInit(T_COLOR5_P gpioObj, T_COLOR5_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __COLOR5_DRV_UART__

void color5_uartDriverInit(T_COLOR5_P gpioObj, T_COLOR5_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint8_t color5_readByte(uint8_t reg)
{
     uint8_t writeReg[ 1 ];
     uint8_t readReg[ 1 ];

     writeReg[ 0 ] = reg;

     hal_i2cStart();
     hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART);
     hal_i2cRead( _slaveAddress, readReg, 1, END_MODE_STOP);

     return readReg[ 0 ];
}

uint16_t color5_readData(uint8_t reg)
{
    uint8_t writeReg [ 1 ];
    uint8_t readReg  [ 2 ];
    uint16_t dataValue;

    writeReg[ 0 ] = reg;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead( _slaveAddress, readReg, 2, END_MODE_STOP);

    dataValue = readReg[ 0 ];
    dataValue = dataValue << 8;
    dataValue = dataValue | readReg[ 1 ];

    return dataValue;
}

void color5_setConfiguration(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 2, END_MODE_STOP );
}

void color5_readAllData(uint16_t *data_buffer)
{
    uint8_t writeReg [ 1 ];
    uint8_t readReg  [ 8 ];

    writeReg[ 0 ] = 0x03;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead( _slaveAddress, readReg, 8, END_MODE_STOP);

    data_buffer[ 0 ] = readReg[ 0 ];
    data_buffer[ 0 ] = data_buffer[ 0 ] << 8;
    data_buffer[ 0 ] = data_buffer[ 0 ] | readReg[ 1 ];
    
    data_buffer[ 1 ] = readReg[ 2 ];
    data_buffer[ 1 ] = data_buffer[ 1 ] << 8;
    data_buffer[ 1 ] = data_buffer[ 1 ] | readReg[ 3 ];
    
    data_buffer[ 2 ] = readReg[ 4 ];
    data_buffer[ 2 ] = data_buffer[ 2 ] << 8;
    data_buffer[ 2 ] = data_buffer[ 2 ] | readReg[ 5 ];
    
    data_buffer[ 3 ] = readReg[ 6 ];
    data_buffer[ 3 ] = data_buffer[ 3 ] << 8;
    data_buffer[ 3 ] = data_buffer[ 3 ] | readReg[ 7 ];
}

uint8_t color5_getInterrupt()
{
    hal_gpio_intGet();
}

void color5_setLedDriver(uint8_t red, uint8_t green, uint8_t blue)
{
    volatile uint8_t ctrl_reg_1;
    volatile uint8_t ctrl_reg_2;
    
    ctrl_reg_1 = _COLOR5_LED_DRIVER_RESET | _COLOR5_LED_DRIVER_DC_MODE;
    ctrl_reg_1 = ctrl_reg_1 | red;
    
    ctrl_reg_2 = green;
    ctrl_reg_2 = ctrl_reg_2 << 4;
    ctrl_reg_2 = ctrl_reg_2 | blue;
    
    color5_setConfiguration(_COLOR5_REG_3_LED_DRIVE_CTRL_1, ctrl_reg_1 );
    color5_setConfiguration(_COLOR5_REG_3_LED_DRIVE_CTRL_2, ctrl_reg_2 );

}

/* -------------------------------------------------------------------------- */
/*
  __color5_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */