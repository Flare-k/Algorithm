 #include <iostream>
 #include <vector>
using namespace std;


/*
시작점에서 도착점까지 이동 가능한가!
경로의 개수를 찾는게 아니므로 visit을 0으로 다시 갱신해줄 필요가 없다.
*/
int map[4][5] = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 1, 0, 0, 0,
    0, 0, 0, 1, 0,
};

int visit[4][5] ;
vector<pair<int, int>> path;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int startX = 3;
int startY = 2;

int endX = 3;
int endY = 4;
int dest;
int cnt = 0;

void run(int x, int y) {
    if (x == endX && y == endY) {
        dest = 1;
        cnt++;
        for (int i = 0; i < path.size(); i++) {
            if (i != path.size() - 1){
                cout << "(" << path[i].first << ", " << path[i].second << ")" << " - ";
            }
            else {
                cout << "(" << path[i].first << ", " << path[i].second << ")";
            }
        }
        cout << '\n';
        return;
    }

    for (int i = 0 ; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 5) continue;
        if (map[nx][ny] == 1) continue;
        if (visit[nx][ny] == 1) continue;

        visit[nx][ny] = 1;
        path.push_back({nx, ny});
        run(nx, ny);
        path.pop_back();
        visit[nx][ny] = 0;  // OX만 찾는거면 이 코드는 필요없다.
    }
}

int main() {
    path.push_back({startX, startY});
    visit[startX][startY] = 1;
    run(startX, startY);

    if (dest) cout << "도착 O" << '\n';
    else cout << "도착 X" << '\n';

    cout << "탐색 가능한 경로의 개수: " << cnt << '\n';

    return 0;
}