#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

typedef struct trieNode {
	struct trieNode *next[ALPHABET_SIZE];

	int count;
} TrieNode;

// Returns new trie node (initialized to NULLs)
TrieNode *createNode()
{
	TrieNode *node = new TrieNode;

	node->count = 1;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		node->next[i] = NULL;

	return node;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(TrieNode *root, string key)
{
	TrieNode *w = root;

	for (int i = 0; i < (int) key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!w->next[index]){
			w->next[index] = createNode();
		}

		// counts one more occurence of this letter
		else{
			w->next[index]->count++;
		}

		w = w->next[index];
	}

}

// Returns true if key presents in trie, else
// false
int search(TrieNode *root, string key, bool remove)
{
	TrieNode *w = root;

	for (int i = 0; i < (int) key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!w->next[index]){
			return false;
		}

		w = w->next[index];

		// removes one occurrence of this letter
		// (this works because it is guaranteed that all the strings to be deleted were given before)
		if (remove){
			w->count--;
		}
	}

	return w->count;
}

void querie(int q, string word, TrieNode *root){
	int count = 0;

	switch (q)
	{
		case 1:
			insert(root, word);
			break;
		
		case 2:
			count = search(root, word, true);
			break;

		case 3:
			count = search(root, word, false);
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

	TrieNode *root = createNode();
	string word;

	while (queries > 0)
	{
		int q;

		cin >> q;
		cin >> word;

		querie(q, word, root);

		queries--;
	}

	return 0;
}