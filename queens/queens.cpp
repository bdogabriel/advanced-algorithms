#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>

// square board
#define BOARD_SIZE 8

// keeps the rank in which each queen stands on the file
int ranks[BOARD_SIZE];

using namespace std;

// checks if position of queen is valid
bool valid(int rank, int file)
{
	for (int p = 0; p < file; p++)
		if (ranks[p] == rank || (abs(ranks[p] - rank) == abs(p - file)))
			return false;

	return true;
}

void backtracking(int file, int board[BOARD_SIZE][BOARD_SIZE], int *score, int *maxScore)
{
	// went through all the files
	if (file == BOARD_SIZE)
	{
		if (*score > *maxScore)
		{
			*maxScore = *score;
		}

		*score = 0;
	}
	
	else
	{
		// for every rank
		for (int rank = 0; rank < BOARD_SIZE; rank++)
		{
			if (valid(rank, file))
			{
				ranks[file] = rank;
				*score += board[rank][file];
				int save = *score;
				backtracking(file + 1, board, score, maxScore);
				*score = save;
				*score -= board[rank][file];
			}
		}
	}
}

int main()
{
	int nBoards = 0;
	int board[8][8];

	cin >> nBoards;

	for (int i = 0; i < nBoards; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				cin >> board[j][k];
			}
		}

		int score = 0;
		int maxScore = 0;

		memset(ranks, 0, sizeof(ranks));
		backtracking(0, board, &score, &maxScore);
		cout << right << setw(5) << fixed << maxScore << endl;
	}

	return 0;
}