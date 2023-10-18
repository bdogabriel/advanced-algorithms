#include<iostream>

using namespace std;

long long int xCoordinates[100001];
long long int yCoordinates[100001];

long long int crossProduct(long long int x1, long long int y1, long long int x2, long long int y2){
    return (x1*y2 - x2*y1);
}

long long int polygonArea(long long int x[], long long int y[], int n){
    long long int area = 0;

    for (int i = 1; i < n; i++){
        // vector of the vertexes coordinates
        long long int vx = x[i] - x[i - 1];
        long long int vy = y[i] - y[i - 1];

        area += crossProduct(vx, vy, x[i - 1], y[i - 1]);
    }

    // the first and the last vertexes
    long long int vx = x[0] - x[n - 1];
    long long int vy = y[0] - y[n - 1];

    area += crossProduct(vx, vy, x[n - 1], y[n - 1]);

    return abs(area);
}

int main(){
    int vertexes;
    cin >> vertexes;

    for(int i = 0; i < vertexes; i++){
        cin >> xCoordinates[i] >> yCoordinates[i];
    }

    cout << polygonArea(xCoordinates, yCoordinates, vertexes);

    return 0;
}