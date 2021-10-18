#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

const int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
const int MAX = 51;
string board[MAX][MAX];
bool visit[2][MAX][MAX];
int N;
int answer = 0;

struct Node {
    int x, y;
    string dir;
    int cnt;
};

bool treeCheck(int nx, int ny, int flag) {
    if (visit[flag][nx][ny]) return false;
    if (flag == 0) {        // 가로
        if (nx >= 0 && nx < N && ny - 1 >= 0 && ny + 1 < N) {
            if (board[nx][ny-1] == "0" && board[nx][ny] == "0" && board[nx][ny+1] == "0") {
                return true;
            }
        }
    }
    else if (flag == 1) {   // 세로
        if (nx-1 >= 0 && nx+1 < N && ny >= 0 && ny < N) {
            if (board[nx-1][ny] == "0" && board[nx][ny] == "0" && board[nx+1][ny] == "0") {
                return true;
            }
        }
    }
    return false;
}

int run(Node s, Node e) {

    if (s.dir == "R") visit[0][s.x][s.y] = true;
    else if (s.dir == "C") visit[1][s.x][s.y] = true;

    queue<Node> q;
    q.push({s.x, s.y, s.dir, s.cnt});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        int flag;
        if (now.dir == "R") flag = 0;
        else flag = 1;

        if (now.x == e.x && now.y == e.y && now.dir == e.dir) {
            answer = now.cnt;
        }

        // 상하좌우 회전 케이스
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            
            if (now.dir == "R") {
                if (treeCheck(nx, ny, flag)) {
                    visit[flag][nx][ny] = true;
                    q.push({nx, ny, now.dir, now.cnt + 1});
                }

            }
            else if (now.dir == "C") {
                if (treeCheck(nx, ny, flag)) {
                    visit[flag][nx][ny] = true;
                    q.push({nx, ny, now.dir, now.cnt + 1});
                }
            }
        }
        
        // 90도 회전 케이스
        int turn = 0;
        for (int i = 0; i < 8; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (board[nx][ny] == "1") continue;
            turn++;
        }

        if (turn < 8) continue;

        if (now.dir == "R") {
            if (treeCheck(now.x, now.y, 1)) {
                visit[1][now.x][now.y] = true;
                q.push({now.x, now.y, "C", now.cnt + 1});
            }
        }
        else if (now.dir == "C") {
            if (treeCheck(now.x, now.y, 0)) {
                visit[0][now.x][now.y] = true;
                q.push({now.x, now.y, "R", now.cnt + 1});
            }
        }
    }
    
    return answer;
}

vector<Node> init() {
    vector<Node> answer;
    string str;
    vector<int> v;
    vector<int> f;

    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            board[i][j] = str[j];
            if (board[i][j] == "B") {
                board[i][j] = "0";
                v.push_back(i);
                v.push_back(j);
            }
            else if (board[i][j] == "E") {
                board[i][j] = "0";
                f.push_back(i);
                f.push_back(j);
            }
        }
    }

    string dir;
    if (v[1] == v[3] && v[1] == v[5]) dir = "C";
    else if (v[0] == v[2] && v[0] == v[4]) dir = "R";

    Node initCase = {v[2], v[3], dir, 0};

    if (f[1] == f[3] && f[1] == f[5]) dir = "C";
    else if (f[0] == f[2] && f[0] == f[4]) dir = "R";
    Node finCase = {f[2], f[3], dir, 0};

    answer.push_back(initCase);
    answer.push_back(finCase);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<Node> vfcase = init();

    cout << run(vfcase[0], vfcase[1]);

    return 0;
}

/*
예외 케이스
5
B0011
B0000
B0000
01000
EEE10
답 : 0

7
0000000
0E00000
0E00BBB
0E01001
0000000
0000001
0100000
답: 5

7
1000111
0000000
B000000
B00100E
B00110E
000100E
1000110
답: 11

5
BBB00
00000
10E00
01E00
00E00
답: 5

5
B0011
B0000
B0000
11000
EEE00
답 : 9

4
000E
BBBE
000E
0000
회전 - 오른쪽 - 오른쪽
답 : 3

4
0B00
EB00
EB00
E000
왼쪽 아래 이동
답 : 2

4
BBB0
0E00
0E00
0E00
답 : 3

5
B0011
B0000
B0000
01000
EEE10
답 : 0

7
0001000
0001000
B00100E
B00000E
B00100E
0001000
0001000
답 : 8
*/