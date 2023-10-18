#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

float average(vector<int> masses, int chambers){
    float average = 0;

    for (int i = 0; i < (int) masses.size(); i++){
        average += masses[i];
    }

    return average / (float) chambers;
}

float sum(vector<int> v){
    float sum = 0;

    for (int i = 0; i < (int) v.size() ; i++){
        sum += v[i];
    }

    return sum;
}

float imbalance(vector<vector<int>> chambers, float avg){
    float imb = 0;

    for (int i = 0; i < (int) chambers.size(); i++){
        float s = sum(chambers[i]);
        imb += abs(avg - s);
    }

    return imb;
}

void output(vector<vector<int>> chambers, int set, float avg){
    cout << "Set #" << set << endl;

    for (int i = 0; i < (int) chambers.size(); i++){
        cout << ' ' << i << ":";

        for (int j = 0; j < (int) chambers[i].size(); j++){
            cout << " " << chambers[i][j];
        }

        cout << endl;
    }

    float imb = imbalance(chambers, avg);

    cout << "IMBALANCE = " << fixed << setprecision(5) << imb << endl << endl;
}

void greedy(vector<vector<int>> &chambers, vector<int> masses, int mSize){
    sort(masses.begin(), masses.end());

    int c = 0;

    for (int i = 0, j = mSize - 1; j >= i; i++, j--){
        if (c == (int) chambers.size()){
            c = 0;
        }
        
        if (masses[i] != 0)
            chambers[c].push_back(masses[i]);

        if (masses[j] != 0)
            chambers[c].push_back(masses[j]);

        c++;
    }
}

int main(){
    int chamb;
    int specs;

    int set = 1;

    while(cin >> chamb >> specs){
        int dummies = 0;

        if (specs < 2 * chamb){
            dummies = 2 * chamb - specs;
        }

        vector<int> masses(specs+dummies, 0);
        vector<vector<int>> chambers(chamb);

        for (int i = 0; i < specs; i++){
            cin >> masses[i];
        }

        int mSize = specs + dummies;

        greedy(chambers, masses, mSize);

        float avg = average(masses, chamb);

        output(chambers, set, avg);

        set++;
    }

    return 0;
}