all: fence.cpp
	g++ -g -o exe fence.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/1.in > out.out