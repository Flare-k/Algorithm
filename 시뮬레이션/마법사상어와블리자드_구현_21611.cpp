#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

const int MAX = 50;
const int tx[] = {0, 1, 0, -1};
const int ty[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, -1, 1};

struct Node {
    int x, y;
};

int arr[MAX][MAX];
int N, M, d, s, dir;
int usedMarble[4];
vector<Node> bomblist;
vector<Node> settinglist;

unordered_map<int, Node> m;

/*
1. 상어의 위치에서 d방향으로 s칸만큼 공격 
2. 자신의 앞칸이 비어있다면 이동
3. 4개이상 연속하는 구슬이 있다면 폭발
4. 폭발한 빈칸에 대한 이동
5. 만약 이동 후에도 4개 이상 연속하는 구슬이 있다면 3,4번 반복 (4개 이상 연속하는 구슬이 없을 때 까지)

나선형을 직렬화하는 방법이 더 쉽다고 함

*/

// 토네이도를 돌며 map에 1 ~ N*N칸의 좌표 초기화
void init(int x, int y) {
    int num = 1;
    int len = 1;

    while (1) {
        if (x == 1 && y == 1) break;

        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < len; i++) {
                int nx = x + tx[dir % 4];
                int ny = y + ty[dir % 4];

                m[num++] = {nx, ny};

                x = nx;
                y = ny;
                
                if (x == 1 && y == 1) return;
            }
            dir++;
        }
        len++;
    }
}

// 블리자드 마법 (d방향으로 s칸 공격)
void Blizzard() {
    int nx = (N+1)/2, ny = (N+1)/2;

    for (int i = 0; i < s; i++) {   // s칸 만큼 이동
        nx += dx[d];
        ny += dy[d];

        if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
        arr[nx][ny] = 0;
    }
}

// 비어있는 칸으로 당기기
void moveMarble() {
    bool flag;

    for (int i = 1; i <= N*N - 1; i++) {
        flag = false;
        int j = i;
        while (arr[m[j].x][m[j].y] == 0) {
            j++;
            flag = true;
            if (m[j].x == 1 && m[j].y == 1) break;
        }

        if (flag) swap(arr[m[i].x][m[i].y], arr[m[j].x][m[j].y]);
        if (m[j].x == 1 && m[j].y == 1) return;
    }
}

// 4개이상의 수가 연속하는지 확인
bool checkBombPossible() {
    int cnt = 1;
    for (int i = 1; i < N*N - 1; i++) {
        if (arr[m[i].x][m[i].y] == arr[m[i + 1].x][m[i + 1].y]) cnt++;
        else {
            if (cnt >= 4) return true;
            cnt = 1;
        }

    }
    return false;
}

// 4개 이상 연속하는 경우 폭발
void bombMarble() {
    int cnt = 1;
    bomblist.clear();

    for (int i = 1; i < N*N - 1; i++) {
        if (arr[m[i].x][m[i].y] == arr[m[i + 1].x][m[i + 1].y]) {
            bomblist.push_back(m[i]);
            cnt++;
        }
        else {
            if (cnt >= 4) {
                bomblist.push_back(m[i]);
                
                if (arr[m[i].x][m[i].y] == 1) {
                    usedMarble[1] += cnt;
                }
                else if (arr[m[i].x][m[i].y] == 2) {
                    usedMarble[2] += 2 * cnt;
                }
                else {
                    usedMarble[3] += 3 * cnt;
                }

                for (auto del : bomblist) {
                    arr[del.x][del.y] = 0;
                }
            }
            bomblist.clear();
            cnt = 1;
        }
    }
}

// (연속하는 수의 개수, 어떤 수) 리스트 생성
void settingMarble() {
    int cnt = 1;
    settinglist.clear();

    for (int i = 1; i < N*N - 1; i++) {
        if (arr[m[i].x][m[i].y] == arr[m[i + 1].x][m[i + 1].y]) cnt++;
        else {
            settinglist.push_back({cnt, arr[m[i].x][m[i].y]});
            cnt = 1;
        }
    }

    int idx = 1;
    for (auto now : settinglist) {
        arr[m[idx].x][m[idx].y] = now.x;
        arr[m[idx + 1].x][m[idx + 1].y] = now.y;
        idx += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    init((N+1)/2, (N+1)/2);

    for (int i = 0; i < M; i++) {
        cin >> d >> s;

        Blizzard(); // 블리자드
        moveMarble();   // 이동
            
        while (checkBombPossible()) {   // 만약 폭발시킬게 있다면?
            bombMarble();   // 폭발
            moveMarble();   // 이동
        }

        settingMarble();
    }

    int answer = 0;
    for (int i = 1; i <= 3; i++) {
        answer += usedMarble[i];
    }

    cout << answer;

    return 0;
}