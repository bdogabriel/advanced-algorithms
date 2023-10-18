#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> read_matrix(char height, char width){
    vector<vector<char>> matrix(height, vector<char>(width));

    for (int i = 0; i < height; i ++){
        for (int j = 0; j < width; j++){
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

bool backtracking(int x, int y, vector<vector<char>> matrix, int height, int width, vector<char> word, int pos){
    if (pos >= (int) word.size()){
        return true;
    }

    if (x >= height || x < 0){
        return false;
    }

    if (y >= width || y < 0){
        return false;
    }

    if (matrix[x][y] == word[pos]){
        pos++;

        matrix[x][y] = 'n'; // invalidating position to avoid comming back here

        x++;

        if(backtracking(x, y, matrix, height, width, word, pos)){
            return true;
        }

        x--;
        y++;

        if(backtracking(x, y, matrix, height, width, word, pos)){
            return true;
        }

        x--;
        y--;

        if(backtracking(x, y, matrix, height, width, word, pos)){
            return true;
        }

        x++;
        y--;

        if(backtracking(x, y, matrix, height, width, word, pos)){
            return true;
        }
    }

    return false;
}

int main(){
    int height, width;
    cin >> height >> width;

    vector<vector<char>> matrix = read_matrix(height, width);

    int wordSize;

    cin >> wordSize;

    vector<char> word(wordSize);

    for (int i = 0; i < wordSize; i++){
        cin >> word[i];
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (matrix[i][j] == word[0]){
                if (backtracking(i, j, matrix, height, width, word, 0)){
                    cout << "Yes" << endl;
                    goto end;
                }
            }
        }
    }

    cout << "No" << endl;

    end:

    return 0;
}