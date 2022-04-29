#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
using namespace std;

int N, L;
int answer;
int board[MAX][MAX];
bool row[MAX][2];   // 0: 우, 1: 좌 (행을 좌에서 우로, 우에서 좌로 탐색하는 경우)
bool col[MAX][2];   // 0: 하, 1: 상 (열을 좌에서 우로, 우에서 좌로 탐색하는 경우)
struct Node {
    int num, cnt;
};
vector<Node> node;

void checkRoad(int r, int c, int dir) {
    bool flag = true;
    int iter = node.size() - 1;
    for (int i = 0; i < iter; i++) {
        if (abs(node[i].num - node[i + 1].num) > 1) return;
        else if (node[i].num + 1 == node[i + 1].num) {
            if (node[i].cnt < L) {
                flag = false;
                return;
            }
            else node[i].cnt -= L;
        }
        else if (node[i].num == node[i + 1].num + 1) {
            if (node[i + 1].cnt < L) {
                flag = false;
                return;
            }
            else node[i + 1].cnt -= L;
        }
    }

    if (flag) {
        if (r != 0) {
            row[r][dir] = true;
            row[r][1 - dir] = true;
        }
        else if (c != 0) {
            col[c][dir] = true;
            col[c][1 - dir] = true;
        }
        answer++;
    }
}

void checkRow() {
    for (int i = 1; i <= N; i++) {
        int num = board[i][1];
        int cnt = 1;
        node.clear();
        for (int j = 2; j <= N; j++) {
            if (num == board[i][j]) cnt++;
            else {
                node.push_back({num, cnt});
                num = board[i][j];
                cnt = 1;
            }
        }

        node.push_back({num, cnt});
        if (!row[i][0]) checkRoad(i, 0, 0); // 좌 -> 우
        reverse(node.begin(), node.end());
        if (!row[i][1]) checkRoad(i, 0, 1); // 우 -> 좌
    }
}

void checkCol() {
    for (int j = 1; j <= N; j++) {
        int num = board[1][j];
        int cnt = 1;
        node.clear();

        for (int i = 2; i <= N; i++) {
            if (num == board[i][j]) cnt++;
            else {
                node.push_back({num, cnt});
                num = board[i][j];
                cnt = 1;
            }
        }

        node.push_back({num, cnt});
        if (!col[j][0]) checkRoad(0, j, 0); // 상 -> 하
        reverse(node.begin(), node.end());
        if (!col[j][1]) checkRoad(0, j, 1); // 하 -> 상
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    checkRow();
    checkCol();
    cout << answer << '\n';

    return 0;
}