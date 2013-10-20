# MPLAB IDE generated this makefile for use with GNU make.
# Project: Grav1.mcp
# Date: Thu Oct 17 00:35:21 2013

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

Grav1.cof : CO_driver.o CONFIG18f26k80.o main.o memcpyram2flash.o CO_stack.o CO_OD.o user.o mpu6050.o
	$(LD) /l"C:\Program Files (x86)\Microchip\MCC18\lib" /k"C:\Program Files (x86)\Microchip\MCC18\lib" "..\CANopen\PIC18_with_Microchip_C18\18f26K80.lkr" "CO_driver.o" "CONFIG18f26k80.o" "main.o" "memcpyram2flash.o" "CO_stack.o" "CO_OD.o" "user.o" "mpu6050.o" /u_CRUNTIME /u_DEBUG /o"Grav1.cof" /M"Grav1.map" /W

CO_driver.o : ../CANopen/PIC18_with_Microchip_C18/CO_driver.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/string.h ../CANopen/CO_errors.h ../CANopen/CANopen.h ../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.h ../CANopen/PIC18_with_Microchip_C18/CO_driver.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/stddef.h ../CANopen/PIC18_with_Microchip_C18/CO_driver.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18cxxx.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18f26k80.h CO_OD.h
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18\CO_driver.c" -fo="CO_driver.o" -D__DEBUG -O-

CONFIG18f26k80.o : ../CANopen/PIC18_with_Microchip_C18/CONFIG18f26k80.c
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18\CONFIG18f26k80.c" -fo="CONFIG18f26k80.o" -D__DEBUG -O-

main.o : ../CANopen/PIC18_with_Microchip_C18/main.c ../CANopen/CO_errors.h ../CANopen/CANopen.h ../CANopen/PIC18_with_Microchip_C18/main.c ../CANopen/PIC18_with_Microchip_C18/CO_driver.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18cxxx.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18f26k80.h CO_OD.h
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18\main.c" -fo="main.o" -D__DEBUG -O-

memcpyram2flash.o : ../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/string.h ../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18cxxx.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18f26k80.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/stddef.h
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18\memcpyram2flash.c" -fo="memcpyram2flash.o" -D__DEBUG -O-

CO_stack.o : ../CANopen/CO_stack.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/string.h ../CANopen/CO_errors.h ../CANopen/CANopen.h ../CANopen/CO_stack.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/stddef.h ../CANopen/PIC18_with_Microchip_C18/CO_driver.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18cxxx.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18f26k80.h CO_OD.h
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "C:\canopennode\_src\CANopen\CO_stack.c" -fo="CO_stack.o" -D__DEBUG -O-

CO_OD.o : CO_OD.c ../CANopen/CO_errors.h ../CANopen/CANopen.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/i2c.h mpu6050.h CO_OD.c ../CANopen/PIC18_with_Microchip_C18/CO_driver.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18cxxx.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18f26k80.h CO_OD.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/pconfig.h
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "CO_OD.c" -fo="CO_OD.o" -D__DEBUG -O-

user.o : user.c ../CANopen/CO_errors.h ../CANopen/CANopen.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/i2c.h mpu6050.h user.c ../CANopen/PIC18_with_Microchip_C18/CO_driver.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18cxxx.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18f26k80.h CO_OD.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/pconfig.h
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "user.c" -fo="user.o" -D__DEBUG -O-

mpu6050.o : mpu6050.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/i2c.h mpu6050.h mpu6050.c ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18cxxx.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/p18f26k80.h ../../../Program\ Files\ (x86)/Microchip/MCC18/h/pconfig.h
	$(CC) -p=18F26K80 /i"C:\Program Files (x86)\Microchip\MCC18\h" -I"C:\canopennode\_src\Grav1" -I"C:\canopennode\_src\CANopen" -I"C:\canopennode\_src\CANopen\PIC18_with_Microchip_C18" "mpu6050.c" -fo="mpu6050.o" -D__DEBUG -O-

clean : 
	$(RM) "CO_driver.o" "CONFIG18f26k80.o" "main.o" "memcpyram2flash.o" "CO_stack.o" "CO_OD.o" "user.o" "mpu6050.o" "Grav1.cof" "Grav1.hex"

