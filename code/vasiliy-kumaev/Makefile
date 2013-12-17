all:
	mkdir -p ./build
	$(CXX) -o ./build/CurrencyConvertor ./library/src/CurrencyConvert.cpp ./sample/CurrencyConvert.cpp ./library/src/CurrencyConvertApplication.cpp -I./

test: all
	./build/CurrencyConvertor