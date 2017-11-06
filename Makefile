
INSTALL_ROOT ?= $(HOME)
INCLUDES := -I"include" -I"$(INSTALL_ROOT)/include"
LIBS := -L"$(INSTALL_ROOT)/lib"

CC := g++
CFLAGS := -std=c++11 -Wall
LDFLAGS := -lm -lutils -lOpenCL -lisaOpenCL -lAstroData -lDedispersion -lIntegration -lSNR

ifdef DEBUG
	CFLAGS += -O0 -g3
else
	CFLAGS += -O3 -g0
endif

ifdef LOFAR
	CFLAGS += -DHAVE_HDF5
	INCLUDES += -I"$(HDF5INCLUDE)"
	LIBS += -L"$(HDF5DIR)"
	LDFLAGS += -lhdf5 -lhdf5_cpp -lz
endif
ifdef PSRDADA
	CFLAGS += -DHAVE_PSRDADA
	INCLUDES += -I"$(PSRDADA)/src"
	DADA_DEPS := $(PSRDADA)/src/dada_hdu.o $(PSRDADA)/src/ipcbuf.o $(PSRDADA)/src/ipcio.o $(PSRDADA)/src/ipcutil.o $(PSRDADA)/src/ascii_header.o $(PSRDADA)/src/multilog.o $(PSRDADA)/src/tmutil.o
endif
ifdef OPENMP
	CFLAGS += -fopenmp
endif

all: bin/Trigger.o bin/TransientSearch

bin/Trigger.o: include/Trigger.hpp src/Trigger.cpp
	-@mkdir -p bin
	$(CC) -o bin/Trigger.o -c src/Trigger.cpp $(INCLUDES) $(CFLAGS)

bin/TransientSearch: include/configuration.hpp src/TransientSearch.cpp
	-@mkdir -p bin
	$(CC) -o bin/amber src/TransientSearch.cpp bin/Trigger.o $(DADA_DEPS) $(INCLUDES) $(LIBS) $(LDFLAGS) $(CFLAGS)

clean:
	-@rm bin/*

install: all
	-@mkdir -p $(INSTALL_ROOT)/bin
	-@cp bin/amber $(INSTALL_ROOT)/bin
