#include <iostream>
#include <cstring>

using namespace std;

int prices[26];
long long int memo[2000][2000];

long long int mostExpensive(int i, int j, char s1[], char s2[], int lenS1, int lenS2)
{
    if (i == lenS1 || j == lenS2)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    long long int cost = 0;

    if (s1[i] == s2[j])
        cost = prices[s1[i] - 97];

    return memo[i][j] = max(max(mostExpensive(i, j + 1, s1, s2, lenS1, lenS2), cost + mostExpensive(i + 1, j + 1, s1, s2, lenS1, lenS2)), mostExpensive(i + 1, j, s1, s2, lenS1, lenS2));
}

int main()
{
    int lenS1, lenS2;

    cin >> lenS1 >> lenS2;

    for (int i = 0; i < 26; i++)
        cin >> prices[i];

    char s1[lenS1];
    char s2[lenS2];

    for (int i = 0; i < lenS1; i++)
        cin >> s1[i];

    for (int i = 0; i < lenS2; i++)
        cin >> s2[i];

    for (int i = 0; i < lenS1; i++)
        memset(memo[i], -1, sizeof memo[i]);

    cout << mostExpensive(0, 0, s1, s2, lenS1, lenS2);

    return 0;
}