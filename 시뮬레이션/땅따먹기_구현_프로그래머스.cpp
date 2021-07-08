#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;

    int size = land.size();
    int nsize = land[0].size();

    vector<vector<int>> acc(size, vector<int>(nsize, 0));

    for (int i = 0; i < nsize; i++) {
        acc[0][i] = land[0][i];
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < nsize; j++) {
            for (int k = 0; k < nsize; k++) {
                if (j == k) continue;   // 이전 행과 같은 열인 경우 continue
                int x = i - 1;
                int y = k;
                acc[i][j] = max(acc[i][j], land[i][j] + acc[x][y]);
            }
        }
    }

    for (int i = 0; i < nsize; i++) {
        answer = max(answer, acc[size - 1][i]);
    }

    return answer;
}

int main() {

    int ans = solution({
        {1, 2, 3, 5},
        {5, 6, 7, 8},
        {4, 3, 2, 1}
    });
    
    cout << ans;

    return 0;
}