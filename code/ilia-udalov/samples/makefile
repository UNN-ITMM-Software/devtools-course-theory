CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp ../src/regex.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=regexpr

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
