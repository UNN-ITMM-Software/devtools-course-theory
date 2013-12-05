all:
	mkdir -p ./build
	$(CXX) -o ./build/quadraticequation ./library/src/QuadraticEquation.cpp ./sample/QuadraticEquation.cpp ./library/src/QuadraticEquation_application -I./ 

test: all
	./build/quadraticequation
