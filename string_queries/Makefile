all: trieQueries.cpp
	g++ -g -o exe trieQueries.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/4.in > out.out