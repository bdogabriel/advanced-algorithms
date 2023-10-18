#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MIN(a, b, c) min(min(a, b), c)

#define MAX 2001

char str1[MAX];
char str2[MAX];

int delta = 1;

int MEMO[MAX + 1][MAX + 1];

int alpha(int i, int j)
{
	char cx = str1[i];
	char cy = str2[j];

	if (cx == cy)
		return 0;

	return 1;
}

int align(int i, int j)
{
	if (i == 0)
	{
		MEMO[0][j] = j * delta;
		return MEMO[0][j];
	}

	if (j == 0)
	{
		MEMO[i][0] = i * delta;
		return MEMO[i][0];
	}

	if (MEMO[i][j] != -1)
		return MEMO[i][j];

	MEMO[i][j] = MIN(alpha(i - 1, j - 1) + align(i - 1, j - 1), delta + align(i - 1, j), delta + align(i, j - 1));

	return MEMO[i][j];
}

int main(int argc, char const *argv[])
{
	int len1, len2;

	int testCases;

	cin >> testCases;

	for (int i = 0; i < testCases; i++)
	{
		scanf("%s", str1);
		scanf("%s", str2);

		len1 = strlen(str1);
		len2 = strlen(str2);

		memset(MEMO, -1, sizeof MEMO);

		cout << align(len1, len2) << endl;
	}

	return 0;
}