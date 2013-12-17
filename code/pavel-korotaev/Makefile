all:
	mkdir -p ./build
	$(CXX) -o ./build/weightconvertor ./library/src/WeightConvertor.cpp ./sample/Sample.cpp ./library/src/weightconvertor_application.cpp -I./ 

test: all
	./build/weightconvertor