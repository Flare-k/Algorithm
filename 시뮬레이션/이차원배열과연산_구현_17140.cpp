#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define MAX 101
using namespace std;

int r, c, k;
int row, col;   // 고정변수
int A[MAX][MAX];
struct Node {
    int num, cnt;
};

map<int, int> rowData[MAX];
map<int, int> colData[MAX];

bool cmp(Node& a, Node&b) {
    if (a.cnt < b.cnt) return true;
    else if (a.cnt == b.cnt) {
        if (a.num < b.num) return true;
    }
    return false;
}

void run() {
    vector<Node> rvec[MAX];
    vector<Node> cvec[MAX];
    
    int nrow = 0, ncol = 0;

    for (int i = 0; i < row; i++) {
        int size = rowData[i].size() * 2;
        ncol = max(ncol, size);
        for (auto rd = rowData[i].begin(); rd != rowData[i].end(); rd++) {
            rvec[i].push_back({rd->first, rd->second});
        }
    }

    for (int i = 0; i < col; i++) {
        int size = colData[i].size() * 2;
        nrow = max(nrow, size);
        for (auto cd = colData[i].begin(); cd != colData[i].end(); cd++) {
            cvec[i].push_back({cd->first, cd->second});
        }
    }

    for (int i = 0; i < row; i++) {
        sort(rvec[i].begin(), rvec[i].end(), cmp);
    }

    for (int i = 0; i < col; i++) {
        sort(cvec[i].begin(), cvec[i].end(), cmp);
    }

    memset(A, 0, sizeof(A));

    if (row >= col) {
        for (int i = 0; i < row; i++) {
            int idx = 0;
            for (int j = 0; j < rvec[i].size(); j++) {
                A[i][idx] = rvec[i][j].num;
                A[i][idx + 1] = rvec[i][j].cnt;
                idx += 2;
            }
        }

        for (int i = 0; i < row; i++) {
            rowData[i].clear();
        }

        for (int i = 0; i < col; i++) {
            colData[i].clear();
        }

        col = ncol;
    }
    else {
        for (int j = 0; j < col; j++) {
            int idx = 0;
            for (int i = 0; i < cvec[j].size(); i++) {
                A[idx][j] = cvec[j][i].num;
                A[idx + 1][j] = cvec[j][i].cnt;
                idx += 2;
            }
        }

        for (int i = 0; i < row; i++) {
            rowData[i].clear();
        }

        for (int i = 0; i < col; i++) {
            colData[i].clear();
        }

        row = nrow;
    }
}

void mapinit() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (A[i][j] != 0 && i < MAX && j < MAX) {
                rowData[i][A[i][j]]++;
                colData[j][A[i][j]]++;
            }
        }
    }
}

void init() {
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    
    row = 3;
    col = 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();
    
    int answer = 0;

    while (A[r - 1][c - 1] != k) {
        if (answer == MAX) {
            answer = -1;
            break;
        }

        mapinit();
        run();
        answer++;
    }

    cout << answer << '\n';

    return 0;
}