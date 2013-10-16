PRJNAME=mathquancalc
BUILD_DIR=./build
O_FILES=$(BUILD_DIR)/mathquancalc.o $(BUILD_DIR)/calc.o

all: $(PRJNAME) 

mathquancalc: $(O_FILES)
	mkdir -p $(BUILD_DIR)
	g++ $(O_FILES) -o $(BUILD_DIR)/$(PRJNAME)

test: all
	$(BUILD_DIR)/$(PRJNAME)

$(BUILD_DIR)/mathquancalc.o: src/mathquancalc.cpp
	g++ -c src/mathquancalc.cpp -o $(BUILD_DIR)/mathquancalc.o

$(BUILD_DIR)/calc.o: samples/calc.cpp
	g++ -c samples/calc.cpp -o $(BUILD_DIR)/calc.o

clean:
	rm -rf  $(BUILD_DIR)/*.o 

