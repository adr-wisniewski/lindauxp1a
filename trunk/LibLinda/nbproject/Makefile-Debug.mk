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
	${OBJECTDIR}/Exception.o \
	${OBJECTDIR}/Linda.o \
	${OBJECTDIR}/Tuple.o \
	${OBJECTDIR}/PipeBase.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libliblinda.a

dist/Debug/GNU-Linux-x86/libliblinda.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${RM} dist/Debug/GNU-Linux-x86/libliblinda.a
	${AR} rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliblinda.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/GNU-Linux-x86/libliblinda.a

${OBJECTDIR}/Exception.o: nbproject/Makefile-${CND_CONF}.mk Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/Exception.o Exception.cpp

${OBJECTDIR}/Linda.o: nbproject/Makefile-${CND_CONF}.mk Linda.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/Linda.o Linda.cpp

${OBJECTDIR}/Tuple.o: nbproject/Makefile-${CND_CONF}.mk Tuple.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tuple.o Tuple.cpp

${OBJECTDIR}/PipeBase.o: nbproject/Makefile-${CND_CONF}.mk PipeBase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/PipeBase.o PipeBase.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libliblinda.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
