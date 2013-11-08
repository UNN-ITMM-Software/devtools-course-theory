PRJNAME=mathquancalc
BUILD_DIR=./build
O_FILES=$(BUILD_DIR)/mathquancalc.o $(BUILD_DIR)/calc.o
#INCLUDE=-I include/

all: pre $(PRJNAME) 

$(PRJNAME): $(O_FILES)
	g++ $(O_FILES) -o $(BUILD_DIR)/$(PRJNAME)

test: all
	$(BUILD_DIR)/$(PRJNAME)

$(BUILD_DIR)/mathquancalc.o: src/mathquancalc.cpp
#	g++ $(INCLUDE) -c src/mathquancalc.cpp -o $(BUILD_DIR)/mathquancalc.o
	g++ -c src/mathquancalc.cpp -o $(BUILD_DIR)/mathquancalc.o

$(BUILD_DIR)/calc.o: samples/calc.cpp
#	g++ $(INCLUDE) -c src/mathquancalc.cpp -o $(BUILD_DIR)/mathquancalc.o
	g++ -c samples/calc.cpp -o $(BUILD_DIR)/calc.o

pre:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf  $(BUILD_DIR)/*.o
