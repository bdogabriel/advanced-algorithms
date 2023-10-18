#include <iostream>
#include <cstring>

using namespace std;

int tickets[3];

int min_value(int *d, int (&memo)[], int size, int i, int value, int days, int last)
{
    if (i == size - 1)
    {
        if (d[i] - d[last] < days)
        {
            return value;
        }

        return value + min(min(tickets[0], tickets[1]), tickets[2]);
    }

    if (memo[i] > -1)
    {
        return value + memo[i];
    }

    // isolated day
    if (d[i + 1] - d[i] > 30)
    {
        memo[i] = min(min(tickets[0], tickets[1]), tickets[2]);

        return value + min_value(d, memo, size, i + 1, memo[i], 0, i);
    }

    int seven, month;

    // calculating where to skip with 7 and 30 days
    int j = i + 1;

    while (j < size - 1 && d[j] - d[i] < 7)
    {
        j++;
    }

    seven = j;

    while (j < size - 1 && d[j] - d[i] < 30)
    {
        j++;
    }

    month = j;

    memo[i] = min(min(min_value(d, memo, size, i + 1, tickets[0], 1, i), min_value(d, memo, size, seven, tickets[1], 7, i)), min_value(d, memo, size, month, tickets[2], 30, i));

    value += memo[i];

    return value;
}

int main()
{
    int n;

    cin >> n;

    int days[n];
    int memo[n];

    memset(memo, -1, sizeof memo);

    for (int i = 0; i < 3; i++)
    {
        cin >> tickets[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    cout << min_value(days, (int(&)[])memo, n, 0, 0, 0, 0) << endl;

    return 0;
}