
#CC  ?= arm-linux-gnueabihf-gcc
#CPP ?= arm-linux-gnueabihf-g++
#OPTS = -Wall -W -O3 -DNDEBUG
CC   = g++
CPP  = g++
DEFS =

OPTS += $(DEFS)

INCLUDE = 

LIBS = 

LDFLAGS = -rdynamic -lpthread -lstdc++

CPPOBJ = main.o
COBJ = 
TARGETNAME=operator

$(TARGETNAME): $(CPPOBJ) $(COBJ)
	-mkdir bin
	$(CC) -o bin/$@ $^ $(LIBS) $(LDFLAGS)
	if [ "$(outputdir)" != "" ]; then cp bin/$@ ../$(outputdir)/; fi

$(CPPOBJ):%.o:%.cpp
	$(CC) $(OPTS) $(INCLUDE) -c $< -o $@

$(COBJ):%.o:%.c
	$(CC) $(OPTS) $(INCLUDE) -c $< -o $@

%.d:%.c
	$(CC) $(OPTS)  $(INCLUDE) -MF"$@" -MM -MT"$@" -MT"$(<:.c=.o)" "$<"

-include $(COBJ:.o=.d)

%.dd:%.cpp
	$(CC) $(OPTS)  $(INCLUDE) -MF"$@" -MM -MT"$@" -MT"$(<:.cpp=.o)" "$<"

-include $(CPPOBJ:.o=.dd)

clean:
	$(RM)  bin/$(TARGETNAME)
	find . -name "*.o"  | xargs $(RM)
	find . -name "*.d"  | xargs $(RM)
	find . -name "*.dd"  | xargs $(RM)

.PHONY: clean

