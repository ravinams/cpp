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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/26737a8a/List1.o \
	${OBJECTDIR}/_ext/26737a8a/Main-AddEven.o \
	${OBJECTDIR}/_ext/26737a8a/Main-list.o \
	${OBJECTDIR}/_ext/26737a8a/MyFileIO.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x
CXXFLAGS=-std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/linkedlisttemplate

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/linkedlisttemplate: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/linkedlisttemplate ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/26737a8a/List1.o: /home/oracle/Desktop/task2/List1.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/26737a8a
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/26737a8a/List1.o /home/oracle/Desktop/task2/List1.cpp

${OBJECTDIR}/_ext/26737a8a/Main-AddEven.o: /home/oracle/Desktop/task2/Main-AddEven.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/26737a8a
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/26737a8a/Main-AddEven.o /home/oracle/Desktop/task2/Main-AddEven.cpp

${OBJECTDIR}/_ext/26737a8a/Main-list.o: /home/oracle/Desktop/task2/Main-list.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/26737a8a
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/26737a8a/Main-list.o /home/oracle/Desktop/task2/Main-list.cpp

${OBJECTDIR}/_ext/26737a8a/MyFileIO.o: /home/oracle/Desktop/task2/MyFileIO.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/26737a8a
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/26737a8a/MyFileIO.o /home/oracle/Desktop/task2/MyFileIO.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
