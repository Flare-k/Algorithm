#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1001;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int iter, r, c, person_x, person_y;
int arr[MAX][MAX];
bool visit[MAX][MAX];

enum {
    EMPTY, WALL, PERSON, FIRE
};

struct Node {
    int x, y;
};

queue<Node> fire;

int run() {
    queue<Node> q;
    q.push({person_x, person_y});

    int answer = 0;

    while (1) {
        answer++;

        int fireSize = fire.size();
        while (fireSize--) {
            Node now = fire.front();
            fire.pop();

            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
                if (arr[nx][ny] == WALL || arr[nx][ny] == FIRE) continue;

                arr[nx][ny] = FIRE;
                fire.push({nx, ny});
            }
        }

        int personCnt = q.size();
        if (personCnt == 0) return -1;

        while (personCnt--) {
            Node person = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = person.x + dx[i];
                int ny = person.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= c || ny >= r) return answer;
                if (visit[nx][ny] || arr[nx][ny] == WALL || arr[nx][ny] == FIRE) continue;

                arr[nx][ny] = PERSON;
                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> iter;

    while (iter--) {
        while (!fire.empty()) fire.pop();
        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));

        cin >> r >> c;

        char ch;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                cin >> ch;

                if (ch == '.') arr[i][j] = EMPTY;
                else if (ch == '#') arr[i][j] = WALL;
                else if (ch == '@') {
                    arr[i][j] = PERSON;
                    person_x = i;
                    person_y = j;
                }
                else if (ch == '*') {
                    arr[i][j] = FIRE;
                    fire.push({i, j});
                }
            }
        }

        int flag = run();
        if (flag == -1) cout << "IMPOSSIBLE" << '\n';
        else cout << flag << '\n';
    }

    return 0;
}