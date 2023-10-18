all: playlist.cpp
	g++ -g -o exe playlist.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/2.in > out.out