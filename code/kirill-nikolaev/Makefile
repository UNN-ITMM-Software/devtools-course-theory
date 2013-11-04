all:
	mkdir -p ./build
	$(CXX) -o ./build/NumConverter ./src/NumConverter.cpp ./samples/devtools-course-task1.cpp -I./include 

test: all
	./build/NumConverter