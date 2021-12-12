#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int LIMIT = 4;
const int MAX = 10;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int N, score;
enum {
    BLUE, GREEN
};

// 블록들이 사라진 후, 파란보드의 남은 블록을 오른쪽으로 이동하는 경우
void moveBlueBlock(int cnt) {
    int idx = MAX - 1;

    while (idx && cnt != 0) {
        bool flag = false;
        for (int i = 0; i < LIMIT; i++) {
            if (visit[i][idx] == true) {
                flag = true;
                idx--;
                break;
            }
        }

        if (!flag) {
            for (int i = 0; i < LIMIT; i++) {    
                for (int j = idx; j >= LIMIT; j--) {
                    arr[i][j] = arr[i][j - 1];
                    visit[i][j] = visit[i][j - 1];
                }
            }
            cnt--;
        }

        if (idx == LIMIT) break;
    }
    
}
// 블록들이 사라진 후, 초록보드의 남은 블록을 오른쪽으로 이동하는 경우
void moveGreenBlock(int cnt) {
    int idx = MAX - 1;

    while (idx && cnt != 0) {
        bool flag = false;
        for (int i = 0; i < LIMIT; i++) {
            if (visit[idx][i] == true) {
                flag = true;
                idx--;
                break;
            }
        }

        if (!flag) {
            for (int i = 0; i < LIMIT; i++) {    
                for (int j = idx; j >= LIMIT; j--) {
                    arr[j][i] = arr[j - 1][i];
                    visit[j][i] = visit[j - 1][i];
                }
            }
            cnt--;
        }

        if (idx == LIMIT) break;
    }
    
}

// 라인에 블록이 가득찼을 경우
int exitCase(int color) {
    bool flag = false;
    int cnt = 0;

    if (color == BLUE) {
        for (int j = MAX - 1; j >= LIMIT + 2; j--) {
            if (visit[0][j] && visit[1][j] && visit[2][j] && visit[3][j]) {
                for (int i = 0; i < LIMIT; i++) {
                    arr[i][j] = 0;
                    visit[i][j] = false;
                }
                flag = true;
                cnt++;
            }
        }
    }
    else if (color == GREEN) {
        for (int i = MAX - 1; i >= LIMIT + 2; i--) {
            if (visit[i][0] && visit[i][1] && visit[i][2] && visit[i][3]) {
                for (int j = 0; j < LIMIT; j++) {
                    arr[i][j] = 0;
                    visit[i][j] = false;
                }
                flag = true;
                cnt++;
            }
        }
    }

    if (flag) score += cnt;

    return cnt;
}

// 특수 범위에 들어왔을 경우
void checkSpecialRange() {
    // 파란 보드
    int blue = 0;
    for (int j = LIMIT; j <= LIMIT + 1; j++) {
        for (int i = 0; i < LIMIT; i++) {
            if (arr[i][j] != 0) {
                blue++;
                break;
            }
        }
    }

    // 초록 보드
    int green = 0;
    for (int i = LIMIT; i <= LIMIT + 1; i++) {
        for (int j = 0; j < LIMIT; j++) {
            if (arr[i][j] != 0) {
                green++;
                break;
            }
        }
    }

    if (blue > 0) {
        for (int j = MAX - blue; j < MAX; j++) {
            for (int i = 0; i < LIMIT; i++) {
                arr[i][j] = 0;
                visit[i][j] = false;
            }
        }
        moveBlueBlock(blue);
    }

    if (green > 0) {
        for (int i = MAX - green; i < MAX; i++) {
            for (int j = 0; j < LIMIT; j++) {
                arr[i][j] = 0;
                visit[i][j] = false;
            }
        }
        moveGreenBlock(green);
    }
}

void run(int t, int x, int y) {
    int nx, ny;
    if (t == 1) {
        nx = x;
        ny = y;
    }
    else if (t == 2) {
        nx = x;
        ny = y + 1;
    }
    else if (t == 3) {
        nx = x + 1;
        ny = y;
    }

    // 파란보드로 블록 이동
    bool flag = false;
    int i;
    for (i = 1; i < MAX - ny; i++) {
        if (visit[x][y + i] == true || visit[nx][ny + i] == true) {
            arr[x][y + i - 1] = t;
            arr[nx][ny + i - 1] = t;
            visit[x][y + i - 1] = true;
            visit[nx][ny + i - 1] = true;
        
            flag = true;
            break;
        }
    }

    if (!flag) {
        i--;
        arr[x][y + i] = t;
        arr[nx][ny + i] = t;
        visit[x][y + i] = true;
        visit[nx][ny + i] = true;
    }

    flag = false;

    // 초록보드로 블록 이동
    for (i = 1; i < MAX - nx; i++) {
        if (visit[x + i][y] == true || visit[nx + i][ny] == true) {
            arr[x + i - 1][y] = t;
            arr[nx + i - 1][ny] = t;
            visit[x + i - 1][y] = true;
            visit[nx + i - 1][ny] = true;
        
            flag = true;
            break;
        }
    }

    if (!flag) {
        i--;
        arr[x + i][y] = t;
        arr[nx + i][ny] = t;
        visit[x + i][y] = true;
        visit[nx + i][ny] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, x, y;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> t >> x >> y;
        run(t, x, y);

        int blue = exitCase(BLUE);
        moveBlueBlock(blue);
        
        int green = exitCase(GREEN);
        moveGreenBlock(green);

        checkSpecialRange();
    }

    cout << score << '\n';

    int cnt = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i][j] != 0) cnt++;
        }
    }

    cout << cnt;

    return 0;
}

/*
9
2 1 0
2 1 0
2 1 0
2 1 0
2 1 0
3 0 2
3 0 2
3 0 3
3 0 3
*/