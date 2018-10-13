#!/usr/bin/env bash


mkdir -p build/obj//fnf

PROJ=/Volumes/repos/r/dev/logic-engine/sdd-utils

DAVE=${PROJ}/dave
SDD=${PROJ}/sdd-package-2
SDD_APP=${SDD}/sdd-2.0
SDD_LIB=${SDD}/libsdd-2.0


# SRC = src/main.c src/getopt.c \
#	  src/fnf/compiler.c src/fnf/fnf.c src/fnf/io.c src/fnf/utils.c
#HEADERS = include/sddapi.h include/compiler.h

gcc -std=c99 -O2 -Wall -finline-functions -Iinclude -DNDEBUG -c ${DAVE}/src/dave.c -o ${DAVE}/build/obj/dave.o
gcc -std=c99 -O2 -Wall -finline-functions -Iinclude -DNDEBUG -c ${SDD_APP}/src/getopt.c -o ${DAVE}/build/obj/getopt.o
gcc -std=c99 -O2 -Wall -finline-functions -Iinclude -DNDEBUG -c ${SDD_APP}/src/fnf/compiler.c -o ${DAVE}/build/obj/fnf/compiler.o
gcc -std=c99 -O2 -Wall -finline-functions -Iinclude -DNDEBUG -c ${SDD_APP}/src/fnf/fnf.c -o ${DAVE}/build/obj/fnf/fnf.o
gcc -std=c99 -O2 -Wall -finline-functions -Iinclude -DNDEBUG -c ${SDD_APP}/src/fnf/io.c -o ${DAVE}/build/obj/fnf/io.o
gcc -std=c99 -O2 -Wall -finline-functions -Iinclude -DNDEBUG -c ${SDD_APP}/src/fnf/utils.c -o ${DAVE}/build/obj/fnf/utils.o
gcc ${DAVE}/build/obj/dave.o ${DAVE}/build/obj/getopt.o ${DAVE}/build/obj/fnf/compiler.o ${DAVE}/build/obj/fnf/fnf.o ${DAVE}/build/obj/fnf/io.o ${DAVE}/build/obj/fnf/utils.o -Llib/Darwin -lsdd -lm -o ${DAVE}/build/dave