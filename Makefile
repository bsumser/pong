CXX= g++
RM= rm -vf
CXXLAGS= -g -lm
LDFLAGS= -lcurses -lpthread
SRC= $(wildcard *.cpp)
OBJFILES= $(patsubst %.cpp, %.o, $(SRC))
PROGFILES= $(patsubst %.cpp, %, $(SRC))

.PHONY: all clean

all: $(PROGFILES)

clean:
	$(RM) $(OBJFILES) $(PROGFILES) *~
## eof Makefile
