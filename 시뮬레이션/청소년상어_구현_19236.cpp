#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define MAX 4
using namespace std;

struct Node {
    int num, dir;
};
struct Dir {
    int x, y, dir;
};
const int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
bool survive[MAX * MAX + 1];
int answer;

void fishMove(vector<vector<Node> >& board, vector<Dir>& fish, int sx, int sy, int sd, int eat) {
    answer = max(answer, eat);

    // 물고기 이동
    for (int num = 1; num <= MAX * MAX; num++) {
        if (!survive[num]) continue;

        int x = fish[num].x;
        int y = fish[num].y;
        
        Node now = board[x][y];

        int d = now.dir;

        for (int i = 0; i < 8; i++) {
            if (d == 9) d = 1;

            int nx = x + dx[d % 9];
            int ny = y + dy[d % 9];

            d++;

            if (nx < 1 || nx > MAX || ny < 1 || ny > MAX) continue;
            if (nx == sx && ny == sy) continue;

            int otherNUm = board[nx][ny].num;            
            board[x][y].dir = d - 1;
            fish[num].dir = d - 1;

            swap(board[x][y], board[nx][ny]);
            swap(fish[num].x, fish[otherNUm].x);
            swap(fish[num].y, fish[otherNUm].y);
            break;
        }
    }

    // 상어 이동
    for (int n = 1; n <= 3; n++) {
        vector<vector<Node> > tmp(MAX + 1, vector<Node>(MAX + 1));
        vector<Dir> cfish(MAX * MAX + 1);
        tmp = board;
        cfish = fish;

        int nx = sx + (dx[sd] * n);
        int ny = sy + (dy[sd] * n);
        if (nx < 1 || nx > MAX || ny < 1 || ny > MAX) continue;
        if (!survive[tmp[nx][ny].num]) continue;
        
        int num = tmp[nx][ny].num;
        int nd = tmp[nx][ny].dir;

        survive[num] = false;
        fishMove(tmp, cfish, nx, ny, nd, eat + num);
        survive[num] = true;
    }
}
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗
// 1, 2, 3, 4, 5, 6, 7, 8

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<Node> > board(MAX + 1, vector<Node>(MAX + 1));
    vector<Dir> fish(MAX * MAX + 1);
    Dir shark;
    int eat = 0;
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++) {
            int n, d;
            cin >> n >> d;

            if (i == 1 && j == 1) {
                shark.x = i;
                shark.y = j;
                shark.dir = d;
                eat = n;
                survive[n] = false;
                board[i][j] = {n, d};   // 상어가 먹었다 해도 물고기끼리 이동하기 위해 값 할당 필요 (!survive[tmp[nx][ny].num] 판단위해)
                fish[n] = {i, j, d};
                continue;
            }

            board[i][j] = {n, d};
            fish[n] = {i, j, d};
            survive[n] = true;
        }
    }

    fishMove(board, fish, shark.x, shark.y, shark.dir, eat);

    cout << answer << '\n';

	return 0;
}
