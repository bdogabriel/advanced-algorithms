all: tickets.cpp
	g++ -g -o exe tickets.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/5.in > out.out