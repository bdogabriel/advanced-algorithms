#include <iostream>
#include <vector>

using namespace std;

string strings;
string pattern;

int border[2000001]; // increased size to fit the '$'

void kmp_pre_processing(string word)
{
	int sizeWord = word.length();
	int i = 0, j = -1;
	border[0] = -1;

	while (i < sizeWord)
	{
		while (j >= 0 && word[i] != word[j])
		{
			j = border[j];
		}

		i++;
		j++;

		border[i] = j;
	}
}

int kmp_querie(string word, bool remove)
{
	int sizeStrings = strings.length();
	int sizeWord = word.length();
	int i = 0, j = 0;
	int count = 0;

	kmp_pre_processing(word);

	while (i < sizeStrings)
	{
		while (strings[i] == '*'){
			i++;
		}

		while (j >= 0 && strings[i] != word[j])
		{
			j = border[j];
		}

		i++;
		j++;

		if (j == sizeWord)
		{
			count++;

			if (remove){
				// i +- 1 because of the '$' added to know the begining and end of word
				for (int k = i + 1 - j; k < i - 1; k++){
					strings[k] = '*';
				}
			}

			j = border[j];
		}
	}

	return count;
}

void querie(int q, string word){
	int count = 0;

	// it adds '$' at the begining and end of words to know where they start and end
	switch (q)
	{
		case 1:
			strings = strings.append("$" + word + "$");
			break;
		
		case 2:
			count = kmp_querie("$" + word + "$", true);
			break;

		case 3:
			count = kmp_querie("$" + word, false);
			cout << count << endl;
			break;
		
		default:
			break;
	}
}

int main()
{
	int queries;

	cin >> queries;

	string word;

	while (queries > 0)
	{
		int q;

		cin >> q;
		cin >> word;

		querie(q, word);

		queries--;
	}

	return 0;
}