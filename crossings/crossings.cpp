#include <iostream>

using namespace std;

long long int merge(long long int *vet, long long int inf, long long int mid, long long int sup)
{

	long long int i = inf;	 // first list
	long long int j = mid + 1; // second list

	// aux array
	long long int k = 0;
	long long int aux[sup - inf + 1];

	long long int count = 0;

	// while both lists have elements
	while (i <= mid && j <= sup)
	{
		if (vet[i] < vet[j]) // no inversion
			aux[k++] = vet[i++];

		else
		{ // found inversion
			aux[k++] = vet[j++];
			count = count + (mid - i + 1); // increments count with first list size
		}
	}

	// copy leftovers from both lists
	// first
	while (i <= mid)
		aux[k++] = vet[i++];

	// second
	while (j <= sup)
		aux[k++] = vet[j++];

	// update original array
	for (long long int i = inf, k = 0; i <= sup; i++, k++)
		vet[i] = aux[k];

	return count;
}

long long int inv(long long int *vet, long long int inf, long long int sup)
{
	// size == 1
	if (inf == sup)
		return 0;

	long long int mid = (inf + sup) / 2;

	long long int left = inv(vet, inf, mid);
	long long int right = inv(vet, mid + 1, sup);
	long long int mer = merge(vet, inf, mid, sup);

	return left + right + mer;
}

int main()
{
	long long int testCases;

	cin >> testCases;

	for (long long int i = 0; i < testCases; i++)
	{
		long long int n;

		cin >> n;

		long long int vet[n];

		for (long long int j = 0; j < n; j++)
			cin >> vet[j];

		cout << inv(vet, 0, n - 1) << endl;
	}

	return 0;
}