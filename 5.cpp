#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solve(vector<vector<int>>& arr) {
    int row = arr.size();
    int col = arr[0].size();
    int result = 0;

    vector<vector<int>> heights(row, vector<int>(col));
    vector<vector<int>> lefts(row, vector<int>(col));

    int count;
    //height
    for (int j = 0; j < col; j++) {
        count = 0;
        for (int i = row-1; i >= 0; i--) {
            if (arr[i][j] == 1) {
                heights[i][j] = ++count;
            } else {
                heights[i][j] = 0;
                count = 0;
            }
        }
    }

    //lefts
    for (int i = 0; i < row; i++) {
        count = 0;
        for (int j = col - 1; j >= 0; j--) {
            if (arr[i][j] == 1) {
                lefts[i][j] = ++count;
            } else {
                lefts[i][j] = 0;
                count = 0;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int h = heights[i][j];
            int l = lefts[i][j];
            int temp = j + l;
            for(int g = j + 1; g < temp; g++) {
                if(h > heights[i][g]) {result = max(result, h * (g - j)); h = heights[i][g];}
            }
            result = max(result, h * l);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout << solve(matrix) << endl;
    return 0;
}