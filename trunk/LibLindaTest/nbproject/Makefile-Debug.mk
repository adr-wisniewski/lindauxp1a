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
	${OBJECTDIR}/Command.o \
	${OBJECTDIR}/CommandCreate.o \
	${OBJECTDIR}/CommandKill.o \
	${OBJECTDIR}/CommandStat.o \
	${OBJECTDIR}/CommandPipe.o

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

${OBJECTDIR}/Command.o: nbproject/Makefile-${CND_CONF}.mk Command.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Linda -MMD -MP -MF $@.d -o ${OBJECTDIR}/Command.o Command.cpp

${OBJECTDIR}/CommandCreate.o: nbproject/Makefile-${CND_CONF}.mk CommandCreate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Linda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandCreate.o CommandCreate.cpp

${OBJECTDIR}/CommandKill.o: nbproject/Makefile-${CND_CONF}.mk CommandKill.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Linda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandKill.o CommandKill.cpp

${OBJECTDIR}/CommandStat.o: nbproject/Makefile-${CND_CONF}.mk CommandStat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Linda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandStat.o CommandStat.cpp

${OBJECTDIR}/CommandPipe.o: nbproject/Makefile-${CND_CONF}.mk CommandPipe.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../Linda -MMD -MP -MF $@.d -o ${OBJECTDIR}/CommandPipe.o CommandPipe.cpp

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
