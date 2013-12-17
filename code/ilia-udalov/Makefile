all:
	mkdir -p ./build
	$(CXX) -o ./build/regex ./library/src/regex.cpp ./sample/regex_sample.cpp ./library/src/regex_application.cpp -I./

test: all
	./build/regex

clean:
	rm -rf ./build