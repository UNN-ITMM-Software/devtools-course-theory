all:
	mkdir -p ./build
	$(CXX) -o ./build/TempConv ./library/src/TemperatureConverter.cpp ./samples/main.cpp ./library/src/TempConvApp.cpp -I./

test: all
	./build/TempConv