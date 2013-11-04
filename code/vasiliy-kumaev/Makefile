all:
	mkdir -p ./build
	$(CXX) -o ./build/currencyconvertor ./src/CurrencyConvert.cpp ./samples/CurrencyConvert.cpp -I./include 

test: all
	./build/currencyconvertor