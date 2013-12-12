all:
	mkdir -p ./build
	$(CXX) -o ./build/TempConv ./library/src/TemperatureConverter.cpp ./samples/main.cpp ./library/src/temp_conv_app.cpp -I./

test: all
	./build/TempConv