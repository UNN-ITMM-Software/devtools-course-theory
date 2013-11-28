all:
	mkdir -p ./build
	$(CXX) -o ./build/calc ./library/src/simplecalc.cpp ./sample/calc.cpp ./library/src/calc_application.cpp -I./

test: all
	./build/calc
