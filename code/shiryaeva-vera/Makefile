all:
	mkdir -p ./build
	$(CXX) -o ./build/calc ./src/BinOctHexCalculator.cpp ./samples/calc.cpp -I./include

test: all
	./build/calc