all:
	mkdir -p ./build
	$(CXX) -o ./build/Triangle_sample ./library/src/Triangle.cpp ./sample/Triangle_sample.cpp ./library/src/Triangle_application.cpp -I./ 
test: all
	./build/Triangle_sample
