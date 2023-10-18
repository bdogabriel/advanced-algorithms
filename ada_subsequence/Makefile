all: ada.cpp
	g++ -g -o exe ada.cpp -Wall -Werror

run: exe
	valgrind ./exe < test_cases/5.in > out.out