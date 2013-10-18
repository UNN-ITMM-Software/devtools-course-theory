CC=g++
CFLAGS=-c -Wall
LDFLAGS=

BUILD_DIR=build
SAMPLE_DIR=samples
SCR_DIR=src

all: pre $(BUILD_DIR)/main.o $(BUILD_DIR)/regex.o
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/regex.o -o regex

test: all
	./regex ./test/example

$(BUILD_DIR)/main.o: $(SAMPLE_DIR)/main.cpp
	g++ -c $(SAMPLE_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/regex.o: $(SCR_DIR)/regex.cpp
	g++ -c $(SCR_DIR)/regex.cpp -o $(BUILD_DIR)/regex.o

pre:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf *.o $(BUILD_DIR)