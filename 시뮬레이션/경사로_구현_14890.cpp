#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 101;
int roads[MAX][MAX];
int N, L;
int cnt;

bool validRoad(vector<int>& r) {
    int num = r.front();
    bool stop = false;

    for (int i = 1; i < N; i++) {
        if (num == r[i]) continue;
        else if (num == r[i] + 1) { // 내리막 경사로
            num--;
            for (int j = i; j < i + L; j++) {
                if (j >= N || num != r[j]) {
                    stop = true;
                    break;
                }

                r[j]++;
            }

            if (stop) break;
            else i += (L - 1);
        }
        else if (num == r[i] - 1) { // 오르막 경사로
            num++;
            for (int j = i - 1; j > i - L - 1; j--) {
                if (j < 0 || num != r[j] + 1) {
                    stop = true;
                    break;
                }

                r[j]--; // 중복 사용을 막기 위해 아예 차이를 늘린다.
            }
        }
        else {
            stop = true;
            break;
        }
    }

    return !stop;
}

void run() {
    vector<int> tmp;
    
    for (int i = 0; i < N; i++) {
        // 가로 ----------------------------
        tmp.clear();

        for (int j = 0; j < N; j++) {
            tmp.push_back(roads[i][j]);
        }

        if (validRoad(tmp) == true) cnt++;

        // 세로 ----------------------------
        tmp.clear();

        for (int j = 0; j < N; j++) {
            tmp.push_back(roads[j][i]);
        }

        if (validRoad(tmp) == true) cnt++;
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> roads[i][j];
        }
    }

    run();

    return 0;
}