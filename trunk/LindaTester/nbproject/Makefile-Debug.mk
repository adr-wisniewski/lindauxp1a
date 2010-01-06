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
	${OBJECTDIR}/ParserCommand.o \
	${OBJECTDIR}/NodeTester.o \
	${OBJECTDIR}/main.o

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
LDLIBSOPTIONS=-L../LibLinda/dist/Debug/GNU-Linux-x86 -L../LibLindaTest/dist/Debug/GNU-Linux-x86

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/lindatester

dist/Debug/GNU-Linux-x86/lindatester: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -Wl,--whole-archive -llinda -llindatest -Wl,--no-whole-archive -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lindatester ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/ParserCommand.o: nbproject/Makefile-${CND_CONF}.mk ParserCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -I../LibLindaTest -MMD -MP -MF $@.d -o ${OBJECTDIR}/ParserCommand.o ParserCommand.cpp

${OBJECTDIR}/NodeTester.o: nbproject/Makefile-${CND_CONF}.mk NodeTester.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -I../LibLindaTest -MMD -MP -MF $@.d -o ${OBJECTDIR}/NodeTester.o NodeTester.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../LibLinda -I../LibLindaTest -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../LibLinda && ${MAKE}  -f Makefile CONF=Debug
	cd ../LibLindaTest && ${MAKE}  -f Makefile CONF=Debug
	cd ../LindaWorker && ${MAKE}  -f Makefile CONF=Debug
	cd ../LindaStorage && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/lindatester

# Subprojects
.clean-subprojects:
	cd ../LibLinda && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../LibLindaTest && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../LindaWorker && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../LindaStorage && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
