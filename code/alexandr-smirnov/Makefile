all:
	mkdir -p ./build
	$(CXX) -o ./build/sorter ./library/src/sort.cpp ./sample/sorter.cpp ./library/src/sort_application.cpp -I./

test: all
	./build/sorter