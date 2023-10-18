all: nimCheater.cpp
	g++ -g -o exe nimCheater.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/1.in > out.out