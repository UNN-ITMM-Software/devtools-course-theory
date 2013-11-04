CC=g++
CFLAGS=-c -Wall
LDFLAGS=

BUILD_DIR=build
SAMPLE_DIR=samples
SCR_DIR=src

all: pre main.o regex.o
	$(CC) $(LDFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/regex.o -o $(BUILD_DIR)/regex

test: all
	$(BUILD_DIR)/regex ./test/example

main.o: $(SAMPLE_DIR)/main.cpp
	$(CC) $(CFLAGS) $(SAMPLE_DIR)/main.cpp -o $(BUILD_DIR)/main.o

regex.o: $(SCR_DIR)/regex.cpp
	$(CC) $(CFLAGS) $(SCR_DIR)/regex.cpp -o $(BUILD_DIR)/regex.o

pre:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf *.o $(BUILD_DIR)