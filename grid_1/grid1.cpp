#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MOD 1000000007

char grid[1000][1000];
vector<vector<pair<long long int, long long int>>> memo(1000, vector<pair<long long int, long long int>>(1000, make_pair(-1, -1)));

void pathsPD(int h, int w, int y, int x, long long int *count)
{
    if (y == h - 1 && x == w - 1)
    {
        *count = (*count + 1) % MOD;
    }

    if (memo[y][x].first > 0)
    {
        *count = (*count + memo[y][x].first) % MOD;
    }

    if (memo[y][x].second > 0)
    {
        *count = (*count + memo[y][x].second) % MOD;
    }

    if (grid[y][x] == '.')
    {
        if (y < h - 1 && memo[y][x].first == -1)
        {
            long long int tmp = 0;
            pathsPD(h, w, y + 1, x, &tmp);
            memo[y][x].first = tmp;

            *count = (*count + tmp) % MOD;
        }

        if (x < w - 1 && memo[y][x].second == -1)
        {
            long long int tmp = 0;
            pathsPD(h, w, y, x + 1, &tmp);
            memo[y][x].second = tmp;

            *count = (*count + tmp) % MOD;
        }
    }
}

void paths(int h, int w, int y, int x, int *count)
{
    if (y == h - 1 && x == w - 1)
    {
        *count = (*count + 1) % MOD;
    }

    if (grid[y][x] == '.')
    {
        if (y < h - 1)
        {
            paths(h, w, y + 1, x, count);
        }

        if (x < w - 1)
        {
            paths(h, w, y, x + 1, count);
        }
    }
}

int main()
{
    int h, w;

    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    long long int count = 0;

    pathsPD(h, w, 0, 0, &count);

    cout << count << endl;

    return 0;
}