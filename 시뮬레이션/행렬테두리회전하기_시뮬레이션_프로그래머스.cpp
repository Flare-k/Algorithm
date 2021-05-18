#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {

    int arr[rows + 1][columns + 1];
    int acc[rows + 1][columns + 1];
    
    memset(arr, 0, sizeof(arr));

    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = num++;
        }
    }

    memcpy(acc, arr, sizeof(acc));

    vector<int> answer;
    for (int i = 0; i < queries.size(); i++) {
        int minNum = 21e8;
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];

        // row1
        for (int k = y1; k < y2; k++) {
            acc[x1][k + 1] = arr[x1][k];
            minNum = min(minNum, arr[x1][k]);
        }
        // row2
        for (int k = y2; k > y1; k--) {
            acc[x2][k - 1] = arr[x2][k];
            minNum = min(minNum, arr[x2][k]);
        }
        // col1
        for (int k = x2; k > x1; k--) {
            acc[k - 1][y1] = arr[k][y1];
            minNum = min(minNum, arr[k][y1]);
        }
        // col2
        for (int k = x1; k < x2; k++) {
            acc[k + 1][y2] = arr[k][y2];
            minNum = min(minNum, arr[k][y2]);
        }

        answer.push_back(minNum);
        memcpy(arr, acc, sizeof(arr));
    }

    return answer;
}

int main() {

    vector<int> ans = solution(10, 10, {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}});

    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}