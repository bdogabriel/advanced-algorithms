all: jump.cpp
	g++ -g -o exe jump.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/1.in > out.out