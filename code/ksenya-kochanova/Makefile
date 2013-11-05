all:
	mkdir -p ./build
	$(CXX) -o ./build/TempConv ./src/TemperatureConverter.cpp ./samples/main.cpp -I./include 

test: all
	./build/TempConv