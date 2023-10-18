all: imbalance.cpp
	g++ -g -o exe imbalance.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/2.in > out.out