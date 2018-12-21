_systemInit:
;Click_Color_5_STM.c,39 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color_5_STM.c,41 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Color_5_STM.c,42 :: 		mikrobus_i2cInit( _MIKROBUS1, &_COLOR5_I2C_CFG[0] );
MOVW	R0, #lo_addr(__COLOR5_I2C_CFG+0)
MOVT	R0, #hi_addr(__COLOR5_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Color_5_STM.c,43 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Color_5_STM.c,44 :: 		mikrobus_logWrite("--- System init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Color_5_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,45 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Color_5_STM.c,46 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Color_5_STM.c,48 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color_5_STM.c,50 :: 		color5_i2cDriverInit( (T_COLOR5_P)&_MIKROBUS1_GPIO, (T_COLOR5_P)&_MIKROBUS1_I2C, 0x2A );
MOVS	R2, #42
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_color5_i2cDriverInit+0
;Click_Color_5_STM.c,52 :: 		color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_SENSOR_RESET | _COLOR5_PROX_RED_LED_CURRENT_64mA);
MOVS	R0, __COLOR5_PROX_SENSOR_RESET
ORR	R0, R0, __COLOR5_PROX_RED_LED_CURRENT_64mA
UXTB	R1, R0
MOVS	R0, __COLOR5_REG_PROX_SENSOR_CTRL_1
BL	_color5_setConfiguration+0
;Click_Color_5_STM.c,53 :: 		color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_2, _COLOR5_PROX_DURATION_64ms | _COLOR5_PROX_PULSES_3pulse );
MOVS	R0, __COLOR5_PROX_DURATION_64ms
ORR	R0, R0, __COLOR5_PROX_PULSES_3pulse
UXTB	R1, R0
MOVS	R0, __COLOR5_REG_PROX_SENSOR_CTRL_2
BL	_color5_setConfiguration+0
;Click_Color_5_STM.c,54 :: 		color5_setConfiguration(_COLOR5_REG_PROX_THRESHOLD, _COLOR5_DEF_PROX_THRESHOLD );
MOVS	R1, __COLOR5_DEF_PROX_THRESHOLD
MOVS	R0, __COLOR5_REG_PROX_THRESHOLD
BL	_color5_setConfiguration+0
;Click_Color_5_STM.c,55 :: 		color5_setConfiguration(_COLOR5_REG_PROX_SENSOR_CTRL_1, _COLOR5_PROX_RED_LED_CURRENT_64mA);
MOVS	R1, __COLOR5_PROX_RED_LED_CURRENT_64mA
MOVS	R0, __COLOR5_REG_PROX_SENSOR_CTRL_1
BL	_color5_setConfiguration+0
;Click_Color_5_STM.c,57 :: 		color5_setLedDriver(_COLOR5_RED_CURRENT_0mA, _COLOR5_GREEN_CURRENT_0mA, _COLOR5_BLUE_CURRENT_32mA);
MOVS	R2, __COLOR5_BLUE_CURRENT_32mA
MOVS	R1, __COLOR5_GREEN_CURRENT_0mA
MOVS	R0, __COLOR5_RED_CURRENT_0mA
BL	_color5_setLedDriver+0
;Click_Color_5_STM.c,59 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Color_5_STM.c,61 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Color_5_STM.c,64 :: 		color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL,_COLOR5_CFG_SENSOR_RESET | _COLOR5_CFG_MANUAL_SETTINGS_MODE );
MOVS	R0, __COLOR5_CFG_SENSOR_RESET
ORR	R0, R0, __COLOR5_CFG_MANUAL_SETTINGS_MODE
UXTB	R1, R0
MOVS	R0, __COLOR5_REG_RGB_SENSOR_CTRL
BL	_color5_setConfiguration+0
;Click_Color_5_STM.c,65 :: 		color5_setConfiguration(_COLOR5_REG_RGB_SENSOR_CTRL, _COLOR5_CFG_LOW_GAIN  | _COLOR5_CFG_MANUAL_SETTINGS_MODE );
MOVS	R0, __COLOR5_CFG_LOW_GAIN
ORR	R0, R0, __COLOR5_CFG_MANUAL_SETTINGS_MODE
UXTB	R1, R0
MOVS	R0, __COLOR5_REG_RGB_SENSOR_CTRL
BL	_color5_setConfiguration+0
;Click_Color_5_STM.c,67 :: 		RED_Data = color5_readData( _COLOR5_REG_OUT_DATA_RED_MSB );
MOVS	R0, __COLOR5_REG_OUT_DATA_RED_MSB
BL	_color5_readData+0
MOVW	R1, #lo_addr(_RED_Data+0)
MOVT	R1, #hi_addr(_RED_Data+0)
STRH	R0, [R1, #0]
;Click_Color_5_STM.c,68 :: 		IntToStr( RED_Data, dataTxt );
SXTH	R0, R0
MOVW	R1, #lo_addr(_dataTxt+0)
MOVT	R1, #hi_addr(_dataTxt+0)
BL	_IntToStr+0
;Click_Color_5_STM.c,69 :: 		mikrobus_logWrite( "RED data : ", _LOG_TEXT );
MOVW	R0, #lo_addr(?lstr2_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Color_5_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,70 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
MOVS	R1, #1
MOVW	R0, #lo_addr(_dataTxt+0)
MOVT	R0, #hi_addr(_dataTxt+0)
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,71 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr3_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Color_5_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,73 :: 		GREEN_Data = color5_readData( _COLOR5_REG_OUT_DATA_GREEN_MSB );
MOVS	R0, __COLOR5_REG_OUT_DATA_GREEN_MSB
BL	_color5_readData+0
MOVW	R1, #lo_addr(_GREEN_Data+0)
MOVT	R1, #hi_addr(_GREEN_Data+0)
STRH	R0, [R1, #0]
;Click_Color_5_STM.c,74 :: 		IntToStr( GREEN_Data, dataTxt );
SXTH	R0, R0
MOVW	R1, #lo_addr(_dataTxt+0)
MOVT	R1, #hi_addr(_dataTxt+0)
BL	_IntToStr+0
;Click_Color_5_STM.c,75 :: 		mikrobus_logWrite( "GREEN data : ", _LOG_TEXT );
MOVW	R0, #lo_addr(?lstr4_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Color_5_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,76 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
MOVS	R1, #1
MOVW	R0, #lo_addr(_dataTxt+0)
MOVT	R0, #hi_addr(_dataTxt+0)
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,77 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr5_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_Color_5_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,79 :: 		BLUE_Data = color5_readData( _COLOR5_REG_OUT_DATA_BLUE_MSB );
MOVS	R0, __COLOR5_REG_OUT_DATA_BLUE_MSB
BL	_color5_readData+0
MOVW	R1, #lo_addr(_BLUE_Data+0)
MOVT	R1, #hi_addr(_BLUE_Data+0)
STRH	R0, [R1, #0]
;Click_Color_5_STM.c,80 :: 		IntToStr( BLUE_Data, dataTxt );
SXTH	R0, R0
MOVW	R1, #lo_addr(_dataTxt+0)
MOVT	R1, #hi_addr(_dataTxt+0)
BL	_IntToStr+0
;Click_Color_5_STM.c,81 :: 		mikrobus_logWrite( "BLUE data : ", _LOG_TEXT );
MOVW	R0, #lo_addr(?lstr6_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_Color_5_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,82 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
MOVS	R1, #1
MOVW	R0, #lo_addr(_dataTxt+0)
MOVT	R0, #hi_addr(_dataTxt+0)
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,83 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr7_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr7_Click_Color_5_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,85 :: 		IR_Data = color5_readData( _COLOR5_REG_OUT_DATA_IR_MSB );
MOVS	R0, __COLOR5_REG_OUT_DATA_IR_MSB
BL	_color5_readData+0
MOVW	R1, #lo_addr(_IR_Data+0)
MOVT	R1, #hi_addr(_IR_Data+0)
STRH	R0, [R1, #0]
;Click_Color_5_STM.c,86 :: 		IntToStr( IR_Data, dataTxt );
SXTH	R0, R0
MOVW	R1, #lo_addr(_dataTxt+0)
MOVT	R1, #hi_addr(_dataTxt+0)
BL	_IntToStr+0
;Click_Color_5_STM.c,87 :: 		mikrobus_logWrite( "IR data : ", _LOG_TEXT );
MOVW	R0, #lo_addr(?lstr8_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr8_Click_Color_5_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,88 :: 		mikrobus_logWrite( dataTxt, _LOG_TEXT );
MOVS	R1, #1
MOVW	R0, #lo_addr(_dataTxt+0)
MOVT	R0, #hi_addr(_dataTxt+0)
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,89 :: 		mikrobus_logWrite( " nm", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr9_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr9_Click_Color_5_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,91 :: 		mikrobus_logWrite("---------------\r\n", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr10_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr10_Click_Color_5_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,94 :: 		if (color5_getInterrupt() == 1)
BL	_color5_getInterrupt+0
CMP	R0, #1
IT	NE
BNE	L_applicationTask2
;Click_Color_5_STM.c,96 :: 		mikrobus_logWrite("Proximity detect", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr11_Click_Color_5_STM+0)
MOVT	R0, #hi_addr(?lstr11_Click_Color_5_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Color_5_STM.c,97 :: 		}
L_applicationTask2:
;Click_Color_5_STM.c,98 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask3:
SUBS	R7, R7, #1
BNE	L_applicationTask3
NOP
NOP
NOP
;Click_Color_5_STM.c,99 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Color_5_STM.c,101 :: 		void main()
;Click_Color_5_STM.c,103 :: 		systemInit();
BL	_systemInit+0
;Click_Color_5_STM.c,104 :: 		applicationInit();
BL	_applicationInit+0
;Click_Color_5_STM.c,106 :: 		while (1)
L_main5:
;Click_Color_5_STM.c,108 :: 		applicationTask();
BL	_applicationTask+0
;Click_Color_5_STM.c,109 :: 		}
IT	AL
BAL	L_main5
;Click_Color_5_STM.c,110 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
