
_systemInit:

;Click_Color_5_PIC.c,39 :: 		void systemInit()
;Click_Color_5_PIC.c,41 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
	CLRF        FARG_mikrobus_gpioInit_bus+0 
	MOVLW       7
	MOVWF       FARG_mikrobus_gpioInit_pin+0 
	MOVLW       1
	MOVWF       FARG_mikrobus_gpioInit_direction+0 
	CALL        _mikrobus_gpioInit+0, 0
;Click_Color_5_PIC.c,42 :: 		mikrobus_i2cInit( _MIKROBUS1, &_COLOR5_I2C_CFG[0] );
	CLRF        FARG_mikrobus_i2cInit_bus+0 
	MOVLW       __COLOR5_I2C_CFG+0
	MOVWF       FARG_mikrobus_i2cInit_cfg+0 
	MOVLW       hi_addr(__COLOR5_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+1 
	MOVLW       higher_addr(__COLOR5_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+2 
	CALL        _mikrobus_i2cInit+0, 0
;Click_Color_5_PIC.c,43 :: 		mikrobus_logInit( _LOG_USBUART, 9600 );
	MOVLW       16
	MOVWF       FARG_mikrobus_logInit_port+0 
	MOVLW       128
	MOVWF       FARG_mikrobus_logInit_baud+0 
	MOVLW       37
	MOVWF       FARG_mikrobus_logInit_baud+1 
	MOVLW       0
	MOVWF       FARG_mikrobus_logInit_baud+2 
	MOVWF       FARG_mikrobus_logInit_baud+3 
	CALL        _mikrobus_logInit+0, 0
;Click_Color_5_PIC.c,44 :: 		mikrobus_logWrite("--- System init ---", _LOG_LINE);
	MOVLW       ?lstr1_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr1_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,45 :: 		Delay_ms( 100 );
	MOVLW       9
	MOVWF       R11, 0
	MOVLW       30
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_systemInit0:
	DECFSZ      R13, 1, 1
	BRA         L_systemInit0
	DECFSZ      R12, 1, 1
	BRA         L_systemInit0
	DECFSZ      R11, 1, 1
	BRA         L_systemInit0
	NOP
;Click_Color_5_PIC.c,46 :: 		}
L_end_systemInit:
	RETURN      0
; end of _systemInit

_applicationInit:

;Click_Color_5_PIC.c,48 :: 		void applicationInit()
;Click_Color_5_PIC.c,50 :: 		color5_i2cDriverInit( (T_COLOR5_P)&_MIKROBUS1_GPIO, (T_COLOR5_P)&_MIKROBUS1_I2C, 0x2A );
	MOVLW       __MIKROBUS1_GPIO+0
	MOVWF       FARG_color5_i2cDriverInit_gpioObj+0 
	MOVLW       hi_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_color5_i2cDriverInit_gpioObj+1 
	MOVLW       higher_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_color5_i2cDriverInit_gpioObj+2 
	MOVLW       __MIKROBUS1_I2C+0
	MOVWF       FARG_color5_i2cDriverInit_i2cObj+0 
	MOVLW       hi_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_color5_i2cDriverInit_i2cObj+1 
	MOVLW       higher_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_color5_i2cDriverInit_i2cObj+2 
	MOVLW       42
	MOVWF       FARG_color5_i2cDriverInit_slave+0 
	CALL        _color5_i2cDriverInit+0, 0
;Click_Color_5_PIC.c,52 :: 		color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_SENSOR_RESET | _COLOR5_PROX_RED_LED_CURRENT_64mA);
	MOVLW       __COLOR5_REG_PROX_SENSOR_CTRL_1
	MOVWF       FARG_color5_setConfiguration_reg+0 
	MOVLW       __COLOR5_PROX_SENSOR_RESET
	MOVWF       R0 
	MOVLW       __COLOR5_PROX_RED_LED_CURRENT_64mA
	IORWF       R0, 0 
	MOVWF       FARG_color5_setConfiguration__data+0 
	CALL        _color5_setConfiguration+0, 0
;Click_Color_5_PIC.c,53 :: 		color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_2, _COLOR5_PROX_DURATION_64ms | _COLOR5_PROX_PULSES_3pulse );
	MOVLW       __COLOR5_REG_PROX_SENSOR_CTRL_2
	MOVWF       FARG_color5_setConfiguration_reg+0 
	MOVLW       __COLOR5_PROX_DURATION_64ms
	MOVWF       R0 
	MOVLW       __COLOR5_PROX_PULSES_3pulse
	IORWF       R0, 0 
	MOVWF       FARG_color5_setConfiguration__data+0 
	CALL        _color5_setConfiguration+0, 0
;Click_Color_5_PIC.c,54 :: 		color5_setConfiguration(_COLOR5_REG_PROX_THRESHOLD, _COLOR5_DEF_PROX_THRESHOLD );
	MOVLW       __COLOR5_REG_PROX_THRESHOLD
	MOVWF       FARG_color5_setConfiguration_reg+0 
	MOVLW       __COLOR5_DEF_PROX_THRESHOLD
	MOVWF       FARG_color5_setConfiguration__data+0 
	CALL        _color5_setConfiguration+0, 0
;Click_Color_5_PIC.c,55 :: 		color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_RED_LED_CURRENT_64mA);
	MOVLW       __COLOR5_REG_PROX_SENSOR_CTRL_1
	MOVWF       FARG_color5_setConfiguration_reg+0 
	MOVLW       __COLOR5_PROX_RED_LED_CURRENT_64mA
	MOVWF       FARG_color5_setConfiguration__data+0 
	CALL        _color5_setConfiguration+0, 0
;Click_Color_5_PIC.c,57 :: 		color5_setLedDriver(_COLOR5_RED_CURRENT_0mA, _COLOR5_GREEN_CURRENT_0mA, _COLOR5_BLUE_CURRENT_32mA);
	MOVLW       __COLOR5_RED_CURRENT_0mA
	MOVWF       FARG_color5_setLedDriver_red+0 
	MOVLW       __COLOR5_GREEN_CURRENT_0mA
	MOVWF       FARG_color5_setLedDriver_green+0 
	MOVLW       __COLOR5_BLUE_CURRENT_32mA
	MOVWF       FARG_color5_setLedDriver_blue+0 
	CALL        _color5_setLedDriver+0, 0
;Click_Color_5_PIC.c,58 :: 		}
L_end_applicationInit:
	RETURN      0
; end of _applicationInit

_applicationTask:

;Click_Color_5_PIC.c,60 :: 		void applicationTask()
;Click_Color_5_PIC.c,63 :: 		color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL,_COLOR5_CFG_SENSOR_RESET | _COLOR5_CFG_MANUAL_SETTINGS_MODE );
	MOVLW       __COLOR5_REG_RGB_SENSOR_CTRL
	MOVWF       FARG_color5_setConfiguration_reg+0 
	MOVLW       __COLOR5_CFG_SENSOR_RESET
	MOVWF       R0 
	MOVLW       __COLOR5_CFG_MANUAL_SETTINGS_MODE
	IORWF       R0, 0 
	MOVWF       FARG_color5_setConfiguration__data+0 
	CALL        _color5_setConfiguration+0, 0
;Click_Color_5_PIC.c,64 :: 		color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL, _COLOR5_CFG_LOW_GAIN  | _COLOR5_CFG_MANUAL_SETTINGS_MODE );
	MOVLW       __COLOR5_REG_RGB_SENSOR_CTRL
	MOVWF       FARG_color5_setConfiguration_reg+0 
	MOVLW       __COLOR5_CFG_LOW_GAIN
	MOVWF       R0 
	MOVLW       __COLOR5_CFG_MANUAL_SETTINGS_MODE
	IORWF       R0, 0 
	MOVWF       FARG_color5_setConfiguration__data+0 
	CALL        _color5_setConfiguration+0, 0
;Click_Color_5_PIC.c,66 :: 		RED_Data = color5_readData( _COLOR5_REG_OUT_DATA_RED_MSB );
	MOVLW       __COLOR5_REG_OUT_DATA_RED_MSB
	MOVWF       FARG_color5_readData_reg+0 
	CALL        _color5_readData+0, 0
	MOVF        R0, 0 
	MOVWF       _RED_Data+0 
	MOVF        R1, 0 
	MOVWF       _RED_Data+1 
;Click_Color_5_PIC.c,67 :: 		IntToStr( RED_Data, dataTxt );
	MOVF        R0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _dataTxt+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;Click_Color_5_PIC.c,68 :: 		mikrobus_logWrite( "RED data : ", _LOG_TEXT );
	MOVLW       ?lstr2_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr2_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,69 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
	MOVLW       _dataTxt+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,70 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
	MOVLW       ?lstr3_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr3_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,72 :: 		GREEN_Data = color5_readData( _COLOR5_REG_OUT_DATA_GREEN_MSB );
	MOVLW       __COLOR5_REG_OUT_DATA_GREEN_MSB
	MOVWF       FARG_color5_readData_reg+0 
	CALL        _color5_readData+0, 0
	MOVF        R0, 0 
	MOVWF       _GREEN_Data+0 
	MOVF        R1, 0 
	MOVWF       _GREEN_Data+1 
;Click_Color_5_PIC.c,73 :: 		IntToStr( GREEN_Data, dataTxt );
	MOVF        R0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _dataTxt+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;Click_Color_5_PIC.c,74 :: 		mikrobus_logWrite( "GREEN data : ", _LOG_TEXT );
	MOVLW       ?lstr4_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr4_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,75 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
	MOVLW       _dataTxt+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,76 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
	MOVLW       ?lstr5_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr5_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,78 :: 		BLUE_Data = color5_readData( _COLOR5_REG_OUT_DATA_BLUE_MSB );
	MOVLW       __COLOR5_REG_OUT_DATA_BLUE_MSB
	MOVWF       FARG_color5_readData_reg+0 
	CALL        _color5_readData+0, 0
	MOVF        R0, 0 
	MOVWF       _BLUE_Data+0 
	MOVF        R1, 0 
	MOVWF       _BLUE_Data+1 
;Click_Color_5_PIC.c,79 :: 		IntToStr( BLUE_Data, dataTxt );
	MOVF        R0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _dataTxt+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;Click_Color_5_PIC.c,80 :: 		mikrobus_logWrite( "BLUE data : ", _LOG_TEXT );
	MOVLW       ?lstr6_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr6_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,81 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
	MOVLW       _dataTxt+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,82 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
	MOVLW       ?lstr7_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr7_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,84 :: 		IR_Data = color5_readData( _COLOR5_REG_OUT_DATA_IR_MSB );
	MOVLW       __COLOR5_REG_OUT_DATA_IR_MSB
	MOVWF       FARG_color5_readData_reg+0 
	CALL        _color5_readData+0, 0
	MOVF        R0, 0 
	MOVWF       _IR_Data+0 
	MOVF        R1, 0 
	MOVWF       _IR_Data+1 
;Click_Color_5_PIC.c,85 :: 		IntToStr( IR_Data, dataTxt );
	MOVF        R0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _dataTxt+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;Click_Color_5_PIC.c,86 :: 		mikrobus_logWrite( "IR data : ", _LOG_TEXT );
	MOVLW       ?lstr8_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr8_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,87 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
	MOVLW       _dataTxt+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_dataTxt+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,88 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
	MOVLW       ?lstr9_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr9_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,90 :: 		mikrobus_logWrite("---------------\r\n", _LOG_LINE);
	MOVLW       ?lstr10_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr10_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,93 :: 		if (color5_getInterrupt() == 1)
	CALL        _color5_getInterrupt+0, 0
	MOVF        R0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_applicationTask1
;Click_Color_5_PIC.c,95 :: 		mikrobus_logWrite("Proximity detect", _LOG_LINE);
	MOVLW       ?lstr11_Click_Color_5_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr11_Click_Color_5_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Color_5_PIC.c,96 :: 		}
L_applicationTask1:
;Click_Color_5_PIC.c,97 :: 		Delay_ms( 500 );
	MOVLW       41
	MOVWF       R11, 0
	MOVLW       150
	MOVWF       R12, 0
	MOVLW       127
	MOVWF       R13, 0
L_applicationTask2:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask2
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask2
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask2
;Click_Color_5_PIC.c,98 :: 		}
L_end_applicationTask:
	RETURN      0
; end of _applicationTask

_main:

;Click_Color_5_PIC.c,100 :: 		void main()
;Click_Color_5_PIC.c,102 :: 		systemInit();
	CALL        _systemInit+0, 0
;Click_Color_5_PIC.c,103 :: 		applicationInit();
	CALL        _applicationInit+0, 0
;Click_Color_5_PIC.c,105 :: 		while (1)
L_main3:
;Click_Color_5_PIC.c,107 :: 		applicationTask();
	CALL        _applicationTask+0, 0
;Click_Color_5_PIC.c,108 :: 		}
	GOTO        L_main3
;Click_Color_5_PIC.c,109 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
