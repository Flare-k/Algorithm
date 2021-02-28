#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int check(int n, int L, vector<vector<int>>& map) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int firstValue = map[i][0];
        bool stop = false;

        for (int j = 1; j < n; j++) {
            if (firstValue == map[i][j]) continue;
            
            // 현재보다 다음 높이가 하나 낮을 때
            else if (firstValue == map[i][j] + 1) {
                firstValue--;

                for (int k = j; k < j + L; k++) {
                    if (k >= n) {        // 범위를 넘는 경우
                        stop = true;
                        break;
                    }
                    if (firstValue != map[i][k]) {  // 둘의 차이가 1 보다 클 때
                        stop = true;
                        break;
                    }
                    
                    map[i][k] += 1;
                }

                if (stop) {
                    break;
                }
                else {
                    j += (L - 1);
                }
            }
            // 현재보다 다음 높이가 하나 높을 때
            else if (firstValue == map[i][j] - 1) {
                firstValue++;

                for (int k = j - 1; k > j - L - 1; k--) {
                    if (k < 0) {        // 범위를 넘는 경우
                        stop = true;
                        break;
                    }
                    if (firstValue != map[i][k] + 1) {  // 둘의 차이가 1보다 크다는 의미
                        stop = true;
                        break;
                    }

                    map[i][k] -=  1;
                }

                if (stop) break;
            }
            // 하나 초과로 높거나 낮을 때.. 이땐 경사로를 놓아도 의미가 없으므로 바로 빠져나와야 함
            else {
                stop = true;
                break;
            }
        }

        if (!stop) cnt++;
    }

    return cnt;
}

int main() {
    init();

    int n, L;
    cin >> n >> L;

    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<vector<int>> mapTranspose(n, vector<int>(n, 0));

    int height;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> height;
            map[i][j] += height;    // 행에 대한 행렬
            mapTranspose[j][i] += height;   // 열에 대한 행렬
        }
    }

    cout << check(n, L, map) + check(n, L, mapTranspose);

    return 0;
}