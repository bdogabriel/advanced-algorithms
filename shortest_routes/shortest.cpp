#include<iostream>
#include<cstring>

using namespace std;

long long int memo[501][501];

// not dealing with negative cycles
void floydWarshall(int graphSize){
    for (int k = 1; k <= graphSize; k++){
        for (int i = 1; i <= graphSize; i++){
            for (int j = 1; j <= graphSize; j++){
                // if is better to take vertex k between i and j
                if (memo[i][k] != -1 && memo[k][j] != -1 && (memo[i][j] == -1 || memo[i][k] + memo[k][j] < memo[i][j])){
                    memo[i][j] = memo[i][k] + memo[k][j];
                }
            }
        }
    }
}

int main(){
    int cities, roads, queries;

    cin >> cities >> roads >> queries;

    memset(memo, -1, sizeof memo);

    for (int i = 1; i <= cities; i++){
        memo[i][i] = 0;
    }

    for (int i = 0; i < roads; i++){
        int c1, c2;
        long long int w;

        cin >> c1 >> c2 >> w;

        memo[c1][c2] = w;

        memo[c2][c1] = w;
    }

    floydWarshall(cities);

    for (int i = 0; i < queries; i++){

        int c1, c2;

        cin >> c1 >> c2;

        cout << memo[c1][c2] << endl;
    }

    return 0;
}