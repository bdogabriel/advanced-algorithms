#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int min_energy(int *h, int (&memo)[], int size, int i, int energy){
    if (i == size - 1){
        return energy;
    }

    if (memo[i] > -1){
        return energy + memo[i];
    }

    int jump = 0;

    if (i < size - 2){
        // lower distance from here to end
        jump = min(min_energy(h, memo, size, i + 1, abs(h[i] - h[i + 1])), min_energy(h, memo, size, i + 2, abs(h[i] - h[i + 2])));
        energy += jump;
    }

    else{
        jump = min_energy(h, memo, size, i + 1, abs(h[i] - h[i + 1]));
        energy += jump;
    }

    memo[i] = jump;

    return energy;
}

int main(){
    int n;

    cin >> n;

    int heights[n];
    int memo[n];

    memset(memo, -1, sizeof memo);

    for (int i = 0; i < n; i++){
        cin >> heights[i];
    }

    cout << min_energy(heights, (int (&)[]) memo, n, 0, 0) << endl;

    return 0;
}