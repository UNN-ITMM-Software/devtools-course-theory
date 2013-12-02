all:
	mkdir -p ./build
	$(CXX) -o ./build/TempConv ./library/src/TemperatureConverter.cpp ./samples/main.cpp ./library/src/TempConv_application.cpp -I./

test: all
	./build/TempConv