#include <iostream>
#include <vector>

#define SIZE 1000001

using namespace std;

string text;
string pattern;

void kmp_pre_processing(int *border, string patt)
{
	int sizep = patt.length();
	int i = 0, j = -1;
	border[0] = -1;

	while (i < sizep)
	{
		while (j >= 0 && patt[i] != patt[j])
		{
			j = border[j];
		}

		i++;
		j++;

		border[i] = j;
	}
}

void kmp(int *border)
{
	int sizet = text.length();
	int sizep = pattern.length();
	int i = 0, j = 0;
	vector<int> indexes;

	while (i < sizet)
	{
		while (j >= 0 && text[i] != pattern[j])
		{
			j = border[j];
		}

		i++;
		j++;

		if (j == sizep)
		{
			indexes.push_back(i - j);
			j = border[j];
		}
	}

	if (!indexes.empty())
	{
		cout << indexes.size() << endl;

		for (auto k : indexes)
		{
			cout << k + 1 << ' ';
		}

		cout << endl;
	}

	else
	{
		cout << "Not Found" << endl;
	}

	cout << endl;
}

int main()
{
	int testCases;

	cin >> testCases;

	int border[SIZE];

	while (testCases > 0)
	{
		cin >> text;
		cin >> pattern;

		kmp_pre_processing(border, pattern);

		kmp(border);

		testCases--;
	}

	return 0;
}