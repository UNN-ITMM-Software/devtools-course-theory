all:
	mkdir -p ./build
	$(CXX) -o ./build/quadraticequation ./library/src/QuadraticEquation.cpp ./sample/QuadraticEquation_sample.cpp ./library/src/QuadraticEquation_application.cpp -I./ 

test: all
	./build/quadraticequation
