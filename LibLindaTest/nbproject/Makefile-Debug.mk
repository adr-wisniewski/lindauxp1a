#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/MessageResult.o \
	${OBJECTDIR}/ResultStat.o \
	${OBJECTDIR}/CommandOutput.o \
	${OBJECTDIR}/CommandCreate.o \
	${OBJECTDIR}/Util.o \
	${OBJECTDIR}/MessageCommand.o \
	${OBJECTDIR}/CommandRead.o \
	${OBJECTDIR}/CommandStat.o \
	${OBJECTDIR}/ParserCommand.o \
	${OBJECTDIR}/CommandInput.o \
	${OBJECTDIR}/CommandKill.o \
	${OBJECTDIR}/ResultBasic.o \
	${OBJECTDIR}/MessageWorkerCommand.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/liblindatest.a

dist/Debug/GNU-Linux-x86/liblindatest.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${RM} dist/Debug/GNU-Linux-x86/liblindatest.a
	${AR} rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblindatest.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/GNU-Linux-x86/liblindatest.a

${OBJECTDIR}/MessageResult.o: nbproject/Makefile-${CND_CONF}.mk MessageResult.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageResult.o MessageResult.cpp

${OBJECTDIR}/ResultStat.o: nbproject/Makefile-${CND_CONF}.mk ResultStat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResultStat.o ResultStat.cpp

${OBJECTDIR}/CommandOutput.o: nbproject/Makefile-${CND_CONF}.mk CommandOutput.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandOutput.o CommandOutput.cpp

${OBJECTDIR}/CommandCreate.o: nbproject/Makefile-${CND_CONF}.mk CommandCreate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandCreate.o CommandCreate.cpp

${OBJECTDIR}/Util.o: nbproject/Makefile-${CND_CONF}.mk Util.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/Util.o Util.cpp

${OBJECTDIR}/MessageCommand.o: nbproject/Makefile-${CND_CONF}.mk MessageCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageCommand.o MessageCommand.cpp

${OBJECTDIR}/CommandRead.o: nbproject/Makefile-${CND_CONF}.mk CommandRead.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandRead.o CommandRead.cpp

${OBJECTDIR}/CommandStat.o: nbproject/Makefile-${CND_CONF}.mk CommandStat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandStat.o CommandStat.cpp

${OBJECTDIR}/ParserCommand.o: nbproject/Makefile-${CND_CONF}.mk ParserCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/ParserCommand.o ParserCommand.cpp

${OBJECTDIR}/CommandInput.o: nbproject/Makefile-${CND_CONF}.mk CommandInput.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandInput.o CommandInput.cpp

${OBJECTDIR}/CommandKill.o: nbproject/Makefile-${CND_CONF}.mk CommandKill.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandKill.o CommandKill.cpp

${OBJECTDIR}/ResultBasic.o: nbproject/Makefile-${CND_CONF}.mk ResultBasic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResultBasic.o ResultBasic.cpp

${OBJECTDIR}/MessageWorkerCommand.o: nbproject/Makefile-${CND_CONF}.mk MessageWorkerCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageWorkerCommand.o MessageWorkerCommand.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/liblindatest.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
