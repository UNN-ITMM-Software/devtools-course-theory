all:
	mkdir -p ./build
	$(CXX) -o ./build/quadraticequation ./library/src/QuadraticEquation.cpp ./sample/QuadraticEquationSample.cpp ./library/src/QuadraticEquationApplication.cpp -I./ 

test: all
	./build/quadraticequation
