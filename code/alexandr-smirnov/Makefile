all:
	mkdir -p ./build
	-std=c++11
	$(CXX) -o ./build/sorter ./library/src/sort.cpp ./sample/sorter.cpp ./library/src/sort_application.cpp -I./

test: all
	./build/sorter
