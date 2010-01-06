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
	${OBJECTDIR}/RequestOutput.o \
	${OBJECTDIR}/MessageResponse.o \
	${OBJECTDIR}/ResponseOutput.o \
	${OBJECTDIR}/Util.o \
	${OBJECTDIR}/MessageRequest.o \
	${OBJECTDIR}/PipeBase.o \
	${OBJECTDIR}/Exception.o \
	${OBJECTDIR}/Query.o \
	${OBJECTDIR}/Linda.o \
	${OBJECTDIR}/Archive.o \
	${OBJECTDIR}/Tuple.o \
	${OBJECTDIR}/RequestInput.o \
	${OBJECTDIR}/ResponseInput.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/liblinda.a

dist/Debug/GNU-Linux-x86/liblinda.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${RM} dist/Debug/GNU-Linux-x86/liblinda.a
	${AR} rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblinda.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/GNU-Linux-x86/liblinda.a

${OBJECTDIR}/RequestOutput.o: nbproject/Makefile-${CND_CONF}.mk RequestOutput.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/RequestOutput.o RequestOutput.cpp

${OBJECTDIR}/MessageResponse.o: nbproject/Makefile-${CND_CONF}.mk MessageResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageResponse.o MessageResponse.cpp

${OBJECTDIR}/ResponseOutput.o: nbproject/Makefile-${CND_CONF}.mk ResponseOutput.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResponseOutput.o ResponseOutput.cpp

${OBJECTDIR}/Util.o: nbproject/Makefile-${CND_CONF}.mk Util.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/Util.o Util.cpp

${OBJECTDIR}/MessageRequest.o: nbproject/Makefile-${CND_CONF}.mk MessageRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageRequest.o MessageRequest.cpp

${OBJECTDIR}/PipeBase.o: nbproject/Makefile-${CND_CONF}.mk PipeBase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/PipeBase.o PipeBase.cpp

${OBJECTDIR}/Exception.o: nbproject/Makefile-${CND_CONF}.mk Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/Exception.o Exception.cpp

${OBJECTDIR}/Query.o: nbproject/Makefile-${CND_CONF}.mk Query.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/Query.o Query.cpp

${OBJECTDIR}/Linda.o: nbproject/Makefile-${CND_CONF}.mk Linda.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/Linda.o Linda.cpp

${OBJECTDIR}/Archive.o: nbproject/Makefile-${CND_CONF}.mk Archive.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/Archive.o Archive.cpp

${OBJECTDIR}/Tuple.o: nbproject/Makefile-${CND_CONF}.mk Tuple.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tuple.o Tuple.cpp

${OBJECTDIR}/RequestInput.o: nbproject/Makefile-${CND_CONF}.mk RequestInput.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/RequestInput.o RequestInput.cpp

${OBJECTDIR}/ResponseInput.o: nbproject/Makefile-${CND_CONF}.mk ResponseInput.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../BoostFiles -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResponseInput.o ResponseInput.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/liblinda.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
