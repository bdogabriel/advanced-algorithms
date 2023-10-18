#include <iostream>
#include <cstring>

using namespace std;

#define MAX 500

int lisREC(int *vet, int i, int *maxl, int (&memo)[])
{
    if (i == 0)
        return 1;

    int largest = 1;
    for (int j = i - 1; j >= 0; j--)
    {
        int value = lisREC(vet, j, maxl, memo) + 1;
        if (vet[i] > vet[j])
            largest = max(value, largest);
    }

    if (*maxl < largest)
        *maxl = largest;

    return largest;
}

int lisRECPD(int *vet, int i, int *maxl, int (&memo)[])
{
    if (i == 0)
    {
        memo[0] = 1;
        return 1;
    }

    if (memo[i] != -1)
        return memo[i];

    int largest = 1;
    for (int j = i - 1; j >= 0; j--)
    {
        int value = lisRECPD(vet, j, maxl, memo) + 1;
        if (vet[i] > vet[j])
            largest = max(value, largest);
    }

    if (*maxl < largest)
        *maxl = largest;

    memo[i] = largest;
    return memo[i];
}

int lisPD(int *vet, int n, int (&memo)[])
{
    memo[0] = 1;

    int maxl = 1;

    for (int i = 1; i < n; i++)
    {
        int largest = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            int value = memo[j] + 1;
            if (vet[i] > vet[j])
                largest = max(value, largest);
        }

        if (maxl < largest)
            maxl = largest;

        memo[i] = largest;
    }

    return maxl;
}

int main()
{
    int n;

    cin >> n;

    int vet[n];
    int memo[n];

    memset(memo, -1, sizeof memo);

    for (int i = 0; i < n; i++)
        cin >> vet[i];

    cout << lisPD(vet, n, (int (&)[])memo);

    return 0;
}