#include<iostream>
#include<cstring>

using namespace std;

int bin_search(long long int *vet, int end, int beg, int x){
    int pos = (end + beg) / 2;

    if (x < vet[pos] && pos - 1 < 0){
        return pos;
    }

    if (x < vet[pos] && x > vet[pos - 1]){
        return pos;
    }

    if (x < vet[pos]){
        return bin_search(vet, pos, beg, x);
    }

    if (x > vet[pos]) {
        return bin_search(vet, end, pos + 1, x);
    }

    return pos;
}

int main(){
    int nSongs, nMoments;

    cin >> nSongs >> nMoments;

    long long int playTime[nSongs];

    long long int sum = 0;

    for (int i = 0; i < nSongs; i++){
        int songPlayedTimes, songDuration;

        cin >> songPlayedTimes;
        cin >> songDuration;

        sum += songPlayedTimes * songDuration;

        playTime[i] = sum;
    }

    for (int i = 0; i < nMoments; i++){
        int moment;

        cin >> moment;

        cout << bin_search(playTime, nSongs - 1, 0, moment) + 1 << endl;
    }

    return 0;
}