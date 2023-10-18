all: grid1.cpp
	g++ -g -o exe grid1.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/4.in > out.out