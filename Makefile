CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=$(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic $(INCLUDES)

exec: bin/exec

bin/exec: ./main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec 

//hello
clean:
	rm -fr bin/* obj/*
