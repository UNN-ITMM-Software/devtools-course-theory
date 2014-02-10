all:
	mkdir -p ./build
	$(CXX) -o ./build/NumConverter ./library/src/NumConverter.cpp ./sample/NumConverterSample.cpp ./library/src/NumConverter_application.cpp -I./

test: all
	./build/NumConverter