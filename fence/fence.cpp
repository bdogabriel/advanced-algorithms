#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;

long long int cross_product(pair<long long int, long long int> v1, pair<long long int, long long int> v2){
    return (v1.first*v2.second - v2.first*v1.second);
}

double distance(pair<long long int, long long int> p1, pair<long long int, long long int> p2){
    return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}

double perimeter(vector<pair<long long int, long long int>> convexHull){
    double p = 0;

    for (int i = 1; i < (int) convexHull.size(); i++){
        p += distance(convexHull[i], convexHull[i - 1]);
    }

    p += distance(convexHull[convexHull.size() - 1], convexHull[0]);

    return p;
}

int main(){
    int vertexes;
    cin >> vertexes;

    vector<pair<long long int, long long int>> points;

    for(int i = 0; i < vertexes; i++){
        long long int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end());

    // LOWER HULL --------------------------------------------------------------
    // create lower hull with first two points
    vector<pair<long long int, long long int>> lowerHull{points[0], points[1]};

    for (int i = 2; i < vertexes; i++){
        while(lowerHull.size() >= 2u){
            pair<long long int, long long int> a = lowerHull[lowerHull.size() - 2];
            pair<long long int, long long int> b = lowerHull[lowerHull.size() - 1];
            pair<long long int, long long int> c = points[i];

            // vector ab
            pair<long long int, long long int> ab = make_pair(b.first - a.first, b.second - a.second);

            // vector ac
            pair<long long int, long long int> ac = make_pair(c.first - a.first, c.second - a.second);

            if (cross_product(ab, ac) < 0){
                lowerHull.pop_back();
            }

            else{
                break;
            }
        }

        lowerHull.push_back(points[i]);
    }

    // UPPER HULL --------------------------------------------------------------
    // create lower hull with last two points
    vector<pair<long long int, long long int>> upperHull{points[vertexes - 1], points[vertexes - 2]};

    for (int i = vertexes - 3; i >= 0; i--){
        while(upperHull.size() >= 2u){
            pair<long long int, long long int> a = upperHull[upperHull.size() - 2];
            pair<long long int, long long int> b = upperHull[upperHull.size() - 1];
            pair<long long int, long long int> c = points[i];

            // vector ab
            pair<long long int, long long int> ab = make_pair(b.first - a.first, b.second - a.second);

            // vector ac
            pair<long long int, long long int> ac = make_pair(c.first - a.first, c.second - a.second);

            if (cross_product(ab, ac) < 0){
                upperHull.pop_back();
            }

            else{
                break;
            }
        }

        upperHull.push_back(points[i]);
    }
    
    // CONVEX HULL
    vector<pair<long long int, long long int>> convexHull = lowerHull;
    convexHull.insert(convexHull.end(), upperHull.begin() + 1, upperHull.begin() + upperHull.size() - 1);

    cout << fixed << setprecision(6) << perimeter(convexHull);

    return 0;
}