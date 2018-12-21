/*
    __color5_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __color5_driver.h
@brief    Color_5 Driver
@mainpage Color_5 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   COLOR5
@brief      Color_5 Click Driver
@{

| Global Library Prefix | **COLOR5** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **apr 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _COLOR5_H_
#define _COLOR5_H_

/** 
 * @macro T_COLOR5_P
 * @brief Driver Abstract type 
 */
#define T_COLOR5_P    const uint8_t*

/** @defgroup COLOR5_COMPILE Compilation Config */              /** @{ */

//  #define   __COLOR5_DRV_SPI__                            /**<     @macro __COLOR5_DRV_SPI__  @brief SPI driver selector */
   #define   __COLOR5_DRV_I2C__                            /**<     @macro __COLOR5_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __COLOR5_DRV_UART__                           /**<     @macro __COLOR5_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup COLOR5_VAR Variables */                           /** @{ */


// Register map
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

// Configuration register
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

// configuration LED Driver register
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

// configuration proximity register
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



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup COLOR5_INIT Driver Initialization */              /** @{ */

#ifdef   __COLOR5_DRV_SPI__
void color5_spiDriverInit(T_COLOR5_P gpioObj, T_COLOR5_P spiObj);
#endif
#ifdef   __COLOR5_DRV_I2C__
void color5_i2cDriverInit(T_COLOR5_P gpioObj, T_COLOR5_P i2cObj, uint8_t slave);
#endif
#ifdef   __COLOR5_DRV_UART__
void color5_uartDriverInit(T_COLOR5_P gpioObj, T_COLOR5_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup COLOR5_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for read data from register
 *
 * @param[in] reg  Register from which will be read
 * @retval two byte data which is read from the register
 *
 * Use this function when you need to reads data from the register
 */
uint16_t color5_readData(uint8_t reg);

/**
 * @brief Functions for read one byte from register
 *
 * @param[in] reg  Register from which will be read
 * @retval one byte data which is read from the register
 *
 * Use this function when you need to reads one byte from the register
 */
uint8_t color5_readByte(uint8_t reg);

/**
 * @brief Functions for read all data
 *
 * @param[out] data_buffer  Buffer to which the data will be written
 *
 * Readable data:
     data_buffer[0] - Red value
     data_buffer[1] - Green value
     data_buffer[2] - Blue value
     data_buffer[3] - IR value
 */
void color5_readAllData(uint16_t *data_buffer);

/**
 * @brief Functions for configuration sensor
 *
 * @param[in]  reg     Register which be set
 * @param[out] _data   Data which be written in the register
 *
 * Registers that can be set and options for settings:
 
        - RGB sensor control:
            - Color sensor reset
            - Sleep functions
            - Color sensor register reset
            - Gain selsection (Low gain or High gain)
            - Intergration mode (fixed time mode or manual settings mode)
            - Integration time settings ( 32us, 0.5ms, 8.2ms or 65.5ms)
        
        - Proximity sensor control:
            - Proximity sensor reset
            - Proximity sensor sleep
            - Proximity sensor RED Led driver current (8mA, 16mA, 32mA or 64mA)
            - Proximity sensor duration selection
            - Pulse count selection
            - Treshold control (default sets 0x10)

        - Color led driver control:
            - 3 Color LED reset
            - 3 color LED sleep
            - DC mode
            - 1/10 mode
            - Red led driver current (8mA, 16mA, 32mA or 64mA)
            - Green led driver current (8mA, 16mA, 32mA or 64mA)
            - Blue led driver current (8mA, 16mA, 32mA or 64mA)
        
 */
void color5_setConfiguration(uint8_t reg, uint8_t _data);

/**
 * @brief Functions for setting color
 *
 * @param[in] red    Red data which be set
 * @param[in] green  Green data which be set
 * @param[in] blue   Blue data which be set
 *
 * Options for sets:
        - R/G/B current set (8mA, 16mA and 32mA)
 *
 * When using the LED in DC mode, set the current for red to 30mA or less and
   that for green and blue to 20mA or less.
 */
void color5_setLedDriver(uint8_t red, uint8_t green, uint8_t blue);

/**
 * @brief Functions for reads interrupt pin
 *
 * @retval status reading from pins
 */
uint8_t color5_getInterrupt();

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Color_5_STM.c
    @example Click_Color_5_TIVA.c
    @example Click_Color_5_CEC.c
    @example Click_Color_5_KINETIS.c
    @example Click_Color_5_MSP.c
    @example Click_Color_5_PIC.c
    @example Click_Color_5_PIC32.c
    @example Click_Color_5_DSPIC.c
    @example Click_Color_5_AVR.c
    @example Click_Color_5_FT90x.c
    @example Click_Color_5_STM.mbas
    @example Click_Color_5_TIVA.mbas
    @example Click_Color_5_CEC.mbas
    @example Click_Color_5_KINETIS.mbas
    @example Click_Color_5_MSP.mbas
    @example Click_Color_5_PIC.mbas
    @example Click_Color_5_PIC32.mbas
    @example Click_Color_5_DSPIC.mbas
    @example Click_Color_5_AVR.mbas
    @example Click_Color_5_FT90x.mbas
    @example Click_Color_5_STM.mpas
    @example Click_Color_5_TIVA.mpas
    @example Click_Color_5_CEC.mpas
    @example Click_Color_5_KINETIS.mpas
    @example Click_Color_5_MSP.mpas
    @example Click_Color_5_PIC.mpas
    @example Click_Color_5_PIC32.mpas
    @example Click_Color_5_DSPIC.mpas
    @example Click_Color_5_AVR.mpas
    @example Click_Color_5_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __color5_driver.h

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