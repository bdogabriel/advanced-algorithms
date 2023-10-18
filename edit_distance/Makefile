all: edit.cpp
	g++ -g -o exe edit.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/7.in > out.out