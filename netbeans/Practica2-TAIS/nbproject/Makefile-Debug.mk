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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1954233655/GrafoNombres.o \
	${OBJECTDIR}/_ext/972950885/SplitString.o \
	${OBJECTDIR}/_ext/1954233655/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practica2-tais.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practica2-tais.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practica2-tais ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1954233655/GrafoNombres.o: ../../Practica2-TAIS/GrafoNombres.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1954233655
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1954233655/GrafoNombres.o ../../Practica2-TAIS/GrafoNombres.cpp

${OBJECTDIR}/_ext/972950885/SplitString.o: ../../Practica2-TAIS/SplitString/SplitString.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972950885
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/972950885/SplitString.o ../../Practica2-TAIS/SplitString/SplitString.cpp

${OBJECTDIR}/_ext/1954233655/main.o: ../../Practica2-TAIS/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1954233655
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1954233655/main.o ../../Practica2-TAIS/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practica2-tais.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
