all:
	mkdir -p ./build
	$(CXX) -o ./build/dist ./library/src/DistanceBetweenVectors.cpp ./samples/dist.cpp ./library/src/DistApplication.cpp -I./

test: all
	./build/dist