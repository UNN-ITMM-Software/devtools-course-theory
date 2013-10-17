all:
	mkdir -p ./build
	$(CXX) -o ./build/calc ./src/complexcalc.cpp ./samples/ComplexCalculator.cpp -I./include
test: all
	./build/calc