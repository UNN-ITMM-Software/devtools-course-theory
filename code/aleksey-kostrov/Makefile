all:
	mkdir -p ./build
	$(CXX) -o ./build/dichotomy_search ./library/src/Dichotomy_Search.cpp ./sample/Dichotomy_Search_sample.cpp ./library/src/Dichotomy_Search_application.cpp -I./ 

test: all
	./build/dichotomy_search