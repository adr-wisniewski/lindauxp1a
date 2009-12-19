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
	${OBJECTDIR}/CommandInput.o \
	${OBJECTDIR}/ResultStat.o \
	${OBJECTDIR}/CommandOutput.o \
	${OBJECTDIR}/CommandCreate.o \
	${OBJECTDIR}/MessageCommand.o \
	${OBJECTDIR}/CommandRead.o \
	${OBJECTDIR}/CommandKill.o \
	${OBJECTDIR}/CommandStat.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libliblindatest.a

dist/Debug/GNU-Linux-x86/libliblindatest.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${RM} dist/Debug/GNU-Linux-x86/libliblindatest.a
	${AR} rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliblindatest.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/GNU-Linux-x86/libliblindatest.a

${OBJECTDIR}/MessageResult.o: nbproject/Makefile-${CND_CONF}.mk MessageResult.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageResult.o MessageResult.cpp

${OBJECTDIR}/CommandInput.o: nbproject/Makefile-${CND_CONF}.mk CommandInput.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandInput.o CommandInput.cpp

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

${OBJECTDIR}/MessageCommand.o: nbproject/Makefile-${CND_CONF}.mk MessageCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageCommand.o MessageCommand.cpp

${OBJECTDIR}/CommandRead.o: nbproject/Makefile-${CND_CONF}.mk CommandRead.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandRead.o CommandRead.cpp

${OBJECTDIR}/CommandKill.o: nbproject/Makefile-${CND_CONF}.mk CommandKill.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandKill.o CommandKill.cpp

${OBJECTDIR}/CommandStat.o: nbproject/Makefile-${CND_CONF}.mk CommandStat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandStat.o CommandStat.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libliblindatest.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
