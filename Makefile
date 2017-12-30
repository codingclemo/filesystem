CC = g++
CXXFLAGS = -pedantic -Wall -Wextra -std=c++11 -ggdb 

LD = g++
LDFLAGS =  		


CPPFILES = $(wildcard *.cpp)
OFILES = $(CPPFILES:.cpp=.o)

PROGRAM = main
ARGUMENTS = 

all: depend run

$(PROGRAM): $(OFILES)
	$(LD) -o $@ $(OFILES)  $(LDFLAGS) 


.PHONY: all clean depend run debug

clean:
	rm -f *.o $(PROGRAM) .depend

run: $(PROGRAM)
	./$(PROGRAM) $(ARGUMENTS)

debug: $(PROGRAM)
	gdb $(PROGRAM) $(ARGUMENTS)


DEPENDFILE = .depend

depend:
	$(CC) $(CXXFLAGS) -MM $(CPPFILES) > $(DEPENDFILE)
	cat $(DEPENDFILE)

-include $(DEPENDFILE)
