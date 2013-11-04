all:
	mkdir -p ./build
	$(CXX) -o ./build/dist ./src/DistanceBetweenVectors.cpp ./samples/dist.cpp -I./include 

test: all
	./build/dist