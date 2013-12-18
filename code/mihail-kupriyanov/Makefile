all:
	mkdir -p ./build
	$(CXX) -o ./build/mathquancalc ./library/src/mathquancalc.cpp ./sample/calc.cpp ./library/src/mathquancalc_application.cpp -I./

test: all
	./build/mathquancalc
