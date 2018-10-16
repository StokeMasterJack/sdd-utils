# SDD C utils

At present, there are no tools yet (not by me anyway)

### Dave's code

I created a little single file app:  dave/src/dave.c

It does two things:

1. Reads an ssd from disk, prints it's its model count
2. Reads a CNF from disk, compiles it to an SDD, prints it's model count

Build system:
- Darwiche used two different build systems:
  1. scons for libsdd-2.0
     scons build file is called SConstruct
  2. Make for sdd-2.0
     Build file: Makefile
- CLion uses CMake by default, which uses CMakeLists.txt for its build file
  You have to use CMake/CMakeLists if you want IDE support.
  CLion use that for it's classpath

- I couldn't get CMake/CMakeLists to build "my code + sdd-package-2"
  So I reverted to a shell script: dave/mk.sh

### sdd-package-2
- The sdd-package-2 is 100% darwiche. The only reason i have it here is because CLion dowesn't let you reference
  external directories
- I do not reference it at all from my code
- There are two sub-projects in sdd-package-2:
  1. lib: libsdd-2.0: this is a C lib. It does all the work.
  2. app. sdd-2.0: this includes:
     - the FNF-to-SDD compiler
     - pre-compiled binaries:
       - bin/sdd-darwin
       - bin/sdd-linux
  3. Some sample CNF files
  4. Some sample code

### SDD Compile times
I did some [SDD compile time trials](compile-times.md) .


