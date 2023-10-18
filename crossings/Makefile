all: crossings.cpp
	g++ -g -o exe crossings.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/1.in > out.out