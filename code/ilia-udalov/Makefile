#CC=g++
CFLAGS=-c -Wall
LDFLAGS=

BUILD_DIR=build
SAMPLE_DIR=samples
SCR_DIR=src

all: pre main.o regex.o
	$(CXX) $(LDFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/regex.o -o $(BUILD_DIR)/regex

test: all
	$(BUILD_DIR)/regex
	$(BUILD_DIR)/regex '.*' 'A' 'Any string!'
	$(BUILD_DIR)/regex '^Yes' 'top' 'No the top of the world'
	$(BUILD_DIR)/regex 'happy' 'sad' 'happyness'

main.o: $(SAMPLE_DIR)/main.cpp
	$(CXX) $(CFLAGS) $(SAMPLE_DIR)/main.cpp -o $(BUILD_DIR)/main.o

regex.o: $(SCR_DIR)/regex.cpp
	$(CXX) $(CFLAGS) $(SCR_DIR)/regex.cpp -o $(BUILD_DIR)/regex.o

pre:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf *.o $(BUILD_DIR)