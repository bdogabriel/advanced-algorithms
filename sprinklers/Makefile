all: sprinklers.cpp
	g++ -g -o exe sprinklers.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/3.in > out.out