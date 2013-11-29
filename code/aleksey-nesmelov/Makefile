all:
	mkdir -p ./build
	$(CXX) -o ./build/fractcalc ./library/src/fractcalc.cpp ./sample/Fraction.cpp ./library/src/fractcalc_application.cpp -I./ 


test: all
	./build/fractcalc