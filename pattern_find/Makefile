all: kmp.cpp
	g++ -g -o exe kmp.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/1.in > out.out