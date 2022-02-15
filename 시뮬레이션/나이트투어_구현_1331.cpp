#include <iostream>
#include <vector>
#define MAX 6
using namespace std;

/*
XOXOX
OXXXO
XX_XX
OXXXO
XOXOX
*/
int map[MAX][MAX];
int visit[MAX][MAX];
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int sx, sy;
struct Node {
    int px, py, x, y;
};

vector<Node> list;

bool checkBoundary(int px, int py, int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = px + dx[i];
        int ny = py + dy[i];

        if (nx == x && ny == y) return true;
    }

    return false;
}

bool checkVisit() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (visit[i][j] != 1) return false;
        }
    }

    for (auto v : list) {
        if (!checkBoundary(v.px, v.py, v.x, v.y)) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char ch;
    int num, pr, pc, r, c;

    cin >> ch >> num;

    pr = 6 - num;
    pc = ch - 'A';
    
    sx = pr;
    sy = pc;

    visit[pr][pc]++;

    for (int i = 1; i < 36; i++) {
        cin >> ch >> num;

        r = 6 - num;
        c = ch - 'A';
        visit[r][c]++;

        list.push_back({pr, pc, r, c});

        pr = r;
        pc = c;
    }

    list.push_back({pr, pc, sx, sy});   // 마지막 지점이 시작 지점으로 돌아갈 수 있는 지점인지

    // visit이 전부 1인지 && 정해진 루트로 갔는지
    if (!checkVisit()) cout << "Invalid" << '\n';
    else cout << "Valid" << '\n';

    return 0;
}