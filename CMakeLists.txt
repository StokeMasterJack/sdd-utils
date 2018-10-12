cmake_minimum_required(VERSION 3.12)
project(sdd-utils)

set(CMAKE_CXX_STANDARD 99)

INCLUDE_DIRECTORIES(/Volumes/repos/r/dev/logic-engine/sdd-c-utils/sdd-package-2/sdd-2.0/src)
INCLUDE_DIRECTORIES(/Volumes/repos/r/dev/logic-engine/sdd-c-utils/sdd-package-2/sdd-2.0/src/fnf)
INCLUDE_DIRECTORIES(dave/src)
INCLUDE_DIRECTORIES(dave/include)

add_executable(cdd_demo
        dave/src/dave.c
        dave/include/compiler.h
        dave/include/sddapi.h
        ../sdd-package-2/sdd-2.0/src/getopt.c
)
