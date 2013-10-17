all:
	mkdir -p ./build
	$(CXX) -o ./build/complexcalc ./src/complexcalc.cpp ./samples/ComplexCalculator.cpp -I./include 

test: all
	./build/complexcalc