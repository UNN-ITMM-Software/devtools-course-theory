all:
	mkdir -p ./build
	$(CXX) -o ./build/converter ./src/AreaConverter.cpp ./samples/converter.cpp -I./include 

test: all
	./build/converter