# Makefile

# the C++ compiler
CXX     = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

# options to pass to the compiler
CXXFLAGS = -O0 -g3 -std=c++11

#ifeq "$(CXXVERSION)" "4.6.3"
#	CXXFLAGS += -std=c++0x
#else
#	CXXFLAGS += -std=c++11
#endif

All: all
all: main 

main: ProjectAllocation.cpp
	$(CXX) $(CXXFLAGS) ProjectAllocation.cpp -o main

# Some cleanup functions, invoked by typing "make clean" or "make deepclean"
deepclean: 
	rm -f *~ *.o main *.exe *.stackdump

clean:
	-rm -f *~ *.o *.stackdump

