all: stringGame.cpp
	g++ -g -o exe stringGame.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/1.in > out.out