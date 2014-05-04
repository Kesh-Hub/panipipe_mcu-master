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
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=DHT11.c HCSR04.c ISR.c PANIPIPE_Main.c USART.c General.c Memory.c Conductivity.c Image.c SIM900.c DataCheck.c Battery.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/DHT11.p1 ${OBJECTDIR}/HCSR04.p1 ${OBJECTDIR}/ISR.p1 ${OBJECTDIR}/PANIPIPE_Main.p1 ${OBJECTDIR}/USART.p1 ${OBJECTDIR}/General.p1 ${OBJECTDIR}/Memory.p1 ${OBJECTDIR}/Conductivity.p1 ${OBJECTDIR}/Image.p1 ${OBJECTDIR}/SIM900.p1 ${OBJECTDIR}/DataCheck.p1 ${OBJECTDIR}/Battery.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/DHT11.p1.d ${OBJECTDIR}/HCSR04.p1.d ${OBJECTDIR}/ISR.p1.d ${OBJECTDIR}/PANIPIPE_Main.p1.d ${OBJECTDIR}/USART.p1.d ${OBJECTDIR}/General.p1.d ${OBJECTDIR}/Memory.p1.d ${OBJECTDIR}/Conductivity.p1.d ${OBJECTDIR}/Image.p1.d ${OBJECTDIR}/SIM900.p1.d ${OBJECTDIR}/DataCheck.p1.d ${OBJECTDIR}/Battery.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/DHT11.p1 ${OBJECTDIR}/HCSR04.p1 ${OBJECTDIR}/ISR.p1 ${OBJECTDIR}/PANIPIPE_Main.p1 ${OBJECTDIR}/USART.p1 ${OBJECTDIR}/General.p1 ${OBJECTDIR}/Memory.p1 ${OBJECTDIR}/Conductivity.p1 ${OBJECTDIR}/Image.p1 ${OBJECTDIR}/SIM900.p1 ${OBJECTDIR}/DataCheck.p1 ${OBJECTDIR}/Battery.p1

# Source Files
SOURCEFILES=DHT11.c HCSR04.c ISR.c PANIPIPE_Main.c USART.c General.c Memory.c Conductivity.c Image.c SIM900.c DataCheck.c Battery.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F25K22
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/DHT11.p1: DHT11.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DHT11.p1.d 
	@${RM} ${OBJECTDIR}/DHT11.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/DHT11.p1  DHT11.c 
	@-${MV} ${OBJECTDIR}/DHT11.d ${OBJECTDIR}/DHT11.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DHT11.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HCSR04.p1: HCSR04.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/HCSR04.p1.d 
	@${RM} ${OBJECTDIR}/HCSR04.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/HCSR04.p1  HCSR04.c 
	@-${MV} ${OBJECTDIR}/HCSR04.d ${OBJECTDIR}/HCSR04.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HCSR04.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ISR.p1: ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ISR.p1.d 
	@${RM} ${OBJECTDIR}/ISR.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/ISR.p1  ISR.c 
	@-${MV} ${OBJECTDIR}/ISR.d ${OBJECTDIR}/ISR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ISR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/PANIPIPE_Main.p1: PANIPIPE_Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PANIPIPE_Main.p1.d 
	@${RM} ${OBJECTDIR}/PANIPIPE_Main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/PANIPIPE_Main.p1  PANIPIPE_Main.c 
	@-${MV} ${OBJECTDIR}/PANIPIPE_Main.d ${OBJECTDIR}/PANIPIPE_Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/PANIPIPE_Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/USART.p1: USART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/USART.p1.d 
	@${RM} ${OBJECTDIR}/USART.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/USART.p1  USART.c 
	@-${MV} ${OBJECTDIR}/USART.d ${OBJECTDIR}/USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/General.p1: General.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/General.p1.d 
	@${RM} ${OBJECTDIR}/General.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/General.p1  General.c 
	@-${MV} ${OBJECTDIR}/General.d ${OBJECTDIR}/General.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/General.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Memory.p1: Memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Memory.p1.d 
	@${RM} ${OBJECTDIR}/Memory.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Memory.p1  Memory.c 
	@-${MV} ${OBJECTDIR}/Memory.d ${OBJECTDIR}/Memory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Memory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Conductivity.p1: Conductivity.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Conductivity.p1.d 
	@${RM} ${OBJECTDIR}/Conductivity.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Conductivity.p1  Conductivity.c 
	@-${MV} ${OBJECTDIR}/Conductivity.d ${OBJECTDIR}/Conductivity.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Conductivity.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Image.p1: Image.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Image.p1.d 
	@${RM} ${OBJECTDIR}/Image.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Image.p1  Image.c 
	@-${MV} ${OBJECTDIR}/Image.d ${OBJECTDIR}/Image.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Image.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SIM900.p1: SIM900.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SIM900.p1.d 
	@${RM} ${OBJECTDIR}/SIM900.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/SIM900.p1  SIM900.c 
	@-${MV} ${OBJECTDIR}/SIM900.d ${OBJECTDIR}/SIM900.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SIM900.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/DataCheck.p1: DataCheck.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DataCheck.p1.d 
	@${RM} ${OBJECTDIR}/DataCheck.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/DataCheck.p1  DataCheck.c 
	@-${MV} ${OBJECTDIR}/DataCheck.d ${OBJECTDIR}/DataCheck.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DataCheck.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Battery.p1: Battery.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Battery.p1.d 
	@${RM} ${OBJECTDIR}/Battery.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Battery.p1  Battery.c 
	@-${MV} ${OBJECTDIR}/Battery.d ${OBJECTDIR}/Battery.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Battery.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/DHT11.p1: DHT11.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DHT11.p1.d 
	@${RM} ${OBJECTDIR}/DHT11.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/DHT11.p1  DHT11.c 
	@-${MV} ${OBJECTDIR}/DHT11.d ${OBJECTDIR}/DHT11.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DHT11.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/HCSR04.p1: HCSR04.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/HCSR04.p1.d 
	@${RM} ${OBJECTDIR}/HCSR04.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/HCSR04.p1  HCSR04.c 
	@-${MV} ${OBJECTDIR}/HCSR04.d ${OBJECTDIR}/HCSR04.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/HCSR04.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ISR.p1: ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ISR.p1.d 
	@${RM} ${OBJECTDIR}/ISR.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/ISR.p1  ISR.c 
	@-${MV} ${OBJECTDIR}/ISR.d ${OBJECTDIR}/ISR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ISR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/PANIPIPE_Main.p1: PANIPIPE_Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PANIPIPE_Main.p1.d 
	@${RM} ${OBJECTDIR}/PANIPIPE_Main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/PANIPIPE_Main.p1  PANIPIPE_Main.c 
	@-${MV} ${OBJECTDIR}/PANIPIPE_Main.d ${OBJECTDIR}/PANIPIPE_Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/PANIPIPE_Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/USART.p1: USART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/USART.p1.d 
	@${RM} ${OBJECTDIR}/USART.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/USART.p1  USART.c 
	@-${MV} ${OBJECTDIR}/USART.d ${OBJECTDIR}/USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/General.p1: General.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/General.p1.d 
	@${RM} ${OBJECTDIR}/General.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/General.p1  General.c 
	@-${MV} ${OBJECTDIR}/General.d ${OBJECTDIR}/General.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/General.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Memory.p1: Memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Memory.p1.d 
	@${RM} ${OBJECTDIR}/Memory.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Memory.p1  Memory.c 
	@-${MV} ${OBJECTDIR}/Memory.d ${OBJECTDIR}/Memory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Memory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Conductivity.p1: Conductivity.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Conductivity.p1.d 
	@${RM} ${OBJECTDIR}/Conductivity.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Conductivity.p1  Conductivity.c 
	@-${MV} ${OBJECTDIR}/Conductivity.d ${OBJECTDIR}/Conductivity.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Conductivity.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Image.p1: Image.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Image.p1.d 
	@${RM} ${OBJECTDIR}/Image.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Image.p1  Image.c 
	@-${MV} ${OBJECTDIR}/Image.d ${OBJECTDIR}/Image.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Image.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SIM900.p1: SIM900.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SIM900.p1.d 
	@${RM} ${OBJECTDIR}/SIM900.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/SIM900.p1  SIM900.c 
	@-${MV} ${OBJECTDIR}/SIM900.d ${OBJECTDIR}/SIM900.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SIM900.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/DataCheck.p1: DataCheck.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DataCheck.p1.d 
	@${RM} ${OBJECTDIR}/DataCheck.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/DataCheck.p1  DataCheck.c 
	@-${MV} ${OBJECTDIR}/DataCheck.d ${OBJECTDIR}/DataCheck.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DataCheck.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Battery.p1: Battery.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Battery.p1.d 
	@${RM} ${OBJECTDIR}/Battery.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/Battery.p1  Battery.c 
	@-${MV} ${OBJECTDIR}/Battery.d ${OBJECTDIR}/Battery.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Battery.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"        -odist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"     -odist/${CND_CONF}/${IMAGE_TYPE}/panipipe_mcu-master.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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
