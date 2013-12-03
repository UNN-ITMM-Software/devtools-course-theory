all:
	mkdir -p ./build
	$(CXX) -o ./build/lengthconvertor ./library/src/LengthConvertor.cpp ./sample/LengthConvertor.cpp ./library/src/LengthConvertorApp.cpp -I./ 

test: all
	./build/lengthconvertor