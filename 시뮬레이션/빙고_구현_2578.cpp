#include <iostream>
#include <unordered_map>
using namespace std;

struct Dir {
    int x, y;
};

int marble[5][5];
bool check[5][5];
unordered_map<int, Dir> m;

bool checkBingo() {
    int cnt = 0;
    int ccnt;
    // 가로
    for (int i = 0; i < 5; i++) {
        ccnt = 0;
        for (int j = 0; j < 5; j++) {
            if (check[i][j]) ccnt++;
        }
        if (ccnt == 5) cnt++;
        if (cnt == 3) return true;
    }
    // 세로
    for (int i = 0; i < 5; i++) {
        ccnt = 0;
        for (int j = 0; j < 5; j++) {
            if (check[j][i]) ccnt++;
        }
        if (ccnt == 5) cnt++;
        if (cnt == 3) return true;
    }

    // \ 대각선 
    ccnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                if (check[i][j]) ccnt++;
            }
        }
        if (ccnt == 5) cnt++;
        if (cnt == 3) return true;
    }
    
    // / 대각선 
    ccnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 4; j >= 0; j--) {
            if (i + j == 4) {
                if (check[i][j]) ccnt++;
            }
        }
        if (ccnt == 5) cnt++;
        if (cnt == 3) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> marble[i][j];
            m[marble[i][j]] = {i, j};
        }
    }

    int d;
    bool flag = false;
    int whatnum = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> d;
            check[m[d].x][m[d].y] = true;
            whatnum++;

            if (checkBingo()) {
                cout << whatnum;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    return 0;
}