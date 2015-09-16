#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Grav1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Grav1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../CO_OD.c ../user.c ../mpu6050.c ../i2cmaster.c ../../CANopen/CO_stack.c ../../CANopen/PIC18_with_Microchip_C18/CONFIG18f26k80.c ../../CANopen/PIC18_with_Microchip_C18/CO_driver.c ../../CANopen/PIC18_with_Microchip_C18/main.c ../../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/CO_OD.o ${OBJECTDIR}/_ext/1472/user.o ${OBJECTDIR}/_ext/1472/mpu6050.o ${OBJECTDIR}/_ext/1472/i2cmaster.o ${OBJECTDIR}/_ext/2062878810/CO_stack.o ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o ${OBJECTDIR}/_ext/2052032549/CO_driver.o ${OBJECTDIR}/_ext/2052032549/main.o ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/CO_OD.o.d ${OBJECTDIR}/_ext/1472/user.o.d ${OBJECTDIR}/_ext/1472/mpu6050.o.d ${OBJECTDIR}/_ext/1472/i2cmaster.o.d ${OBJECTDIR}/_ext/2062878810/CO_stack.o.d ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o.d ${OBJECTDIR}/_ext/2052032549/CO_driver.o.d ${OBJECTDIR}/_ext/2052032549/main.o.d ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/CO_OD.o ${OBJECTDIR}/_ext/1472/user.o ${OBJECTDIR}/_ext/1472/mpu6050.o ${OBJECTDIR}/_ext/1472/i2cmaster.o ${OBJECTDIR}/_ext/2062878810/CO_stack.o ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o ${OBJECTDIR}/_ext/2052032549/CO_driver.o ${OBJECTDIR}/_ext/2052032549/main.o ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o

# Source Files
SOURCEFILES=../CO_OD.c ../user.c ../mpu6050.c ../i2cmaster.c ../../CANopen/CO_stack.c ../../CANopen/PIC18_with_Microchip_C18/CONFIG18f26k80.c ../../CANopen/PIC18_with_Microchip_C18/CO_driver.c ../../CANopen/PIC18_with_Microchip_C18/main.c ../../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Grav1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F26K80
MP_PROCESSOR_OPTION_LD=18f26k80
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/CO_OD.o: ../CO_OD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CO_OD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CO_OD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/CO_OD.o   ../CO_OD.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/CO_OD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CO_OD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/user.o: ../user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/user.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/user.o   ../user.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/user.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/mpu6050.o: ../mpu6050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu6050.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu6050.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/mpu6050.o   ../mpu6050.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/mpu6050.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/mpu6050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/i2cmaster.o: ../i2cmaster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2cmaster.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2cmaster.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/i2cmaster.o   ../i2cmaster.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/i2cmaster.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/i2cmaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2062878810/CO_stack.o: ../../CANopen/CO_stack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2062878810" 
	@${RM} ${OBJECTDIR}/_ext/2062878810/CO_stack.o.d 
	@${RM} ${OBJECTDIR}/_ext/2062878810/CO_stack.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2062878810/CO_stack.o   ../../CANopen/CO_stack.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2062878810/CO_stack.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2062878810/CO_stack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o: ../../CANopen/PIC18_with_Microchip_C18/CONFIG18f26k80.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o   ../../CANopen/PIC18_with_Microchip_C18/CONFIG18f26k80.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/CO_driver.o: ../../CANopen/PIC18_with_Microchip_C18/CO_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CO_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CO_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/CO_driver.o   ../../CANopen/PIC18_with_Microchip_C18/CO_driver.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/CO_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/CO_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/main.o: ../../CANopen/PIC18_with_Microchip_C18/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/main.o   ../../CANopen/PIC18_with_Microchip_C18/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o: ../../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o   ../../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1472/CO_OD.o: ../CO_OD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CO_OD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CO_OD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/CO_OD.o   ../CO_OD.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/CO_OD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CO_OD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/user.o: ../user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/user.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/user.o   ../user.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/user.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/mpu6050.o: ../mpu6050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu6050.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu6050.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/mpu6050.o   ../mpu6050.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/mpu6050.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/mpu6050.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/i2cmaster.o: ../i2cmaster.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2cmaster.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2cmaster.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/i2cmaster.o   ../i2cmaster.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/i2cmaster.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/i2cmaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2062878810/CO_stack.o: ../../CANopen/CO_stack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2062878810" 
	@${RM} ${OBJECTDIR}/_ext/2062878810/CO_stack.o.d 
	@${RM} ${OBJECTDIR}/_ext/2062878810/CO_stack.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2062878810/CO_stack.o   ../../CANopen/CO_stack.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2062878810/CO_stack.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2062878810/CO_stack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o: ../../CANopen/PIC18_with_Microchip_C18/CONFIG18f26k80.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o   ../../CANopen/PIC18_with_Microchip_C18/CONFIG18f26k80.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/CONFIG18f26k80.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/CO_driver.o: ../../CANopen/PIC18_with_Microchip_C18/CO_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CO_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/CO_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/CO_driver.o   ../../CANopen/PIC18_with_Microchip_C18/CO_driver.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/CO_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/CO_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/main.o: ../../CANopen/PIC18_with_Microchip_C18/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/main.o   ../../CANopen/PIC18_with_Microchip_C18/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o: ../../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052032549" 
	@${RM} ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DCANnodeID_ON_SWITCH -I"c:/Program Files (x86)/Microchip/MCC18/h" -I"../../CANopen" -I"../../CANopen/PIC18_with_Microchip_C18" -I"../" -I".." -I"." -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o   ../../CANopen/PIC18_with_Microchip_C18/memcpyram2flash.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052032549/memcpyram2flash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Grav1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../CANopen/PIC18_with_Microchip_C18/18f26K80.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\..\CANopen\PIC18_with_Microchip_C18\18f26K80.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../../../../../../../Program Files (x86)/Microchip/MCC18/lib" -l"."  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_ICD3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Grav1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/Grav1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../CANopen/PIC18_with_Microchip_C18/18f26K80.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\..\CANopen\PIC18_with_Microchip_C18\18f26K80.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../../../../../../../Program Files (x86)/Microchip/MCC18/lib" -l"."  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Grav1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
