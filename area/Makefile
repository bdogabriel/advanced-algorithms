all: area.cpp
	g++ -g -o exe area.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/5.in > out.out