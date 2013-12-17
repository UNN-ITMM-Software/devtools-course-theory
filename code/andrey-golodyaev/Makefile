all:
	mkdir -p ./build
	$(CXX) -o ./build/complexcalc ./library/src/complexcalc.cpp ./sample/ComplexCalculator.cpp ./library/src/complexcalc_application.cpp -I./ 

test: all
	./build/complexcalc