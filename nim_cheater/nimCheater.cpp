#include <iostream>

using namespace std;

int main()
{
    long long t, m;
    cin >> t;

    while (t--)
    {
        cin >> m;

        long long arr[m + 5];
        long long x = 0;

        for (long long i = 0; i < m; i++)
            cin >> arr[i], x ^= arr[i];

        if (x != 0)
            cout << 0 << endl;

        else
            cout << 1 << endl;
    }

    return 0;
}