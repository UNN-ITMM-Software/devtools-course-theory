all:
	mkdir -p ./build
	$(CXX) -o ./build/currencyconvertor ./library/src/CurrencyConvert.cpp ./sample/CurrencyConvert.cpp ./library/src/currencyconvert_application.cpp -I./

test: all
	./build/currencyconvertor