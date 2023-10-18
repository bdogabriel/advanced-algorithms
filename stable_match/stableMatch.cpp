#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// gets the first free man in the vector of engaged people
short int get_free(vector<short int> vEngaged)
{
    for (short int i = 0; i < (short int)vEngaged.size(); i++)
    {
        if (vEngaged[i] == -1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    short int testCases;

    cin >> testCases;

    for (short int i = 0; i < testCases; i++)
    {
        short int marriages;
        cin >> marriages;

        // women
        vector<vector<short int>> wPreference(marriages);
        vector<short int> wEngaged(marriages, -1);

        for (short int j = 0; j < marriages; j++)
        {
            short int m;
            cin >> m; // trash (index of person)

            for (short int k = 0; k < marriages; k++)
            {
                cin >> m;
                m--; // to work with indexes from 0
                wPreference[j].push_back(m);
            }
        }

        // men
        vector<vector<pair<short int, bool>>> mPreference(marriages); // pair (woman, not proposed)
        vector<short int> mEngaged(marriages, -1);

        for (short int j = 0; j < marriages; j++)
        {
            short int w;
            cin >> w; // trash (index of person)

            for (short int k = 0; k < marriages; k++)
            {
                cin >> w;
                w--;
                mPreference[j].push_back(make_pair(w, true));
            }
        }

        short int m;

        // stable match
        do
        {
            m = get_free(mEngaged);
            short int w = -1;

            // there is no free man
            if (m == -1)
                break;

            // getting first woman in man's list to whom he has not yet proposed
            for (short int j = 0; j < marriages; j++)
            {
                if (mPreference[m][j].second)
                {
                    w = mPreference[m][j].first;
                    mPreference[m][j].second = false; // propose
                    break;
                }
            }

            if (w != -1 && wEngaged[w] == -1)
            {
                mEngaged[m] = w;
                wEngaged[w] = m;
            }

            else
            {
                vector<short int>::iterator mIndex = find(wPreference[w].begin(), wPreference[w].end(), m);
                vector<short int>::iterator fianceIndex = find(wPreference[w].begin(), wPreference[w].end(), wEngaged[w]);

                // if w prefers m to her fiance
                if (distance(mIndex, fianceIndex) > 0)
                {
                    mEngaged[m] = w;
                    wEngaged[w] = m;

                    short int ind = distance(wPreference[w].begin(), fianceIndex);
                    short int newFree = wPreference[w][ind];

                    mEngaged[newFree] = -1;
                }
            }
        } while (m != -1);

        for (short int j = 0; j < marriages; j++)
        {
            cout << (j + 1) << " " << (mEngaged[j] + 1) << endl;
        }
    }

    return 0;
}