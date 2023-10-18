#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int main()
{
    double nSprinklers, length, width;

    while (cin >> nSprinklers >> length >> width)
    {
        vector<pair<double, double>> spr(nSprinklers);

        for (int i = 0; i < nSprinklers; i++)
        {
            double pos, rad;
            cin >> pos >> rad;

            spr[i].second = sqrt((4 * rad * rad) - (width * width));
            spr[i].first = pos - (spr[i].second / 2);

            spr[i].second += spr[i].first;

            if (spr[i].first < 0)
            {
                spr[i].first = 0;
            }

            if (rad * 2 <= width)
            {
                spr[i].second = -1;
                spr[i].first = -1;
            }
        }

        sort(spr.begin(), spr.end());

        double lastPos = 0;

        int count = 0;

        int i = 0;

        while (i < nSprinklers && lastPos < length)
        {
            double tempEnd = lastPos;

            // bad sprinkler
            if (spr[i].first == -1)
            {
                i++;
                continue;
            }

            // there is a gap
            if (spr[i].first > lastPos)
            {
                break;
            }

            // interval contained in last interval
            if (spr[i].first <= lastPos && spr[i].second < tempEnd)
            {
                i++;
            }

            while (i < nSprinklers && spr[i].first <= lastPos && spr[i].second >= tempEnd)
            {
                tempEnd = spr[i].second;
                i++;
            }

            lastPos = tempEnd;
            count++;
        }

        if (lastPos < length)
        {
            count = -1;
        }

        cout << count << endl;
    }

    return 0;
}