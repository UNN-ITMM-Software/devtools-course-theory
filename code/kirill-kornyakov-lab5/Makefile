all:
	mkdir -p ./build
	$(CXX) -o ./build/calc ./src/simplecalc.cpp ./samples/calc.cpp -I./include 

test: all
	./build/calc
