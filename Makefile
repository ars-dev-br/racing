CPP = g++
CPPFLAGS = -O2 -Wall -Wextra -c -g --std=c++11
LDFLAGS =
LIBS = -lm -lGL -lglut -lGLU -lSOIL

DEPS = $(wildcard *.hpp)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = racing

.PHONY: all doc clean cleandoc

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CPP) $(LDFLAGS) $(LIBS) $(OBJECTS) -o $@

.cpp.o: $(DEPS)
	$(CPP) $(CPPFLAGS) $< -o $@

doc:
	doxygen Doxyfile

clean:
	rm $(EXECUTABLE) *.o

cleandoc:
	rm -rf html latex
