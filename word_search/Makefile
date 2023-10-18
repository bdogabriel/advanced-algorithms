all: wordSearch.cpp
	g++ -g -o exe wordSearch.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/2.in > out.out