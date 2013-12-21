all:
	mkdir -p ./build
	$(CXX) -o ./build/converter ./library/src/AreaConverter.cpp ./samples/converter.cpp ./library/src/AreaConverterApp.cpp -I./

test: all
	./build/converter