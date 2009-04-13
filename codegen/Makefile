# this Makefile compiles every cpp file into a separate executable
# TODO: something wrong with this, not quite working right when doing a partial make
CXXFLAGS+=-I../include

SOURCES=$(wildcard *.cpp)
BINARIES=$(patsubst %.cpp, %, $(SOURCES))
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

bins: $(BINARIES)
#for the clean target
CLEANUP+=$(BINARIES)

-include ../Makefile.include


%:%.o

