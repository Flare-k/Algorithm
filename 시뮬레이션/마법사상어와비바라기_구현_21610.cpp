#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;
const int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
const int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int N, M;
int A[MAX][MAX];    // (r, c)에 있는 바구이에 저장된 물의 양
bool cloud[MAX][MAX];
bool tmpCloud[MAX][MAX];

// 4. 물복사
void checkCloud() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cloud[i][j]) {
                for (int k = 2; k <= 8; k += 2) {   // 대각
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                    if (A[nx][ny] > 0) A[i][j]++;
                }
                
                cloud[i][j] = false;
            }
        }
    }
}

// 5. 2 이상인 부분으로 구름 생성, 각 칸의 대각에 구름이 있다면 그 수만큼 증가
void changeCloudAreaAndCheck() {
    // 구름 생성
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i][j] >= 2 && tmpCloud[i][j] == false) {
                cloud[i][j] = true;
                A[i][j] -= 2;
            }
        }
    }

}

// 1 ~ 5.
void moveCloudAndRain(int d, int s) {
    // d 방향, s 칸 이동, cloud check
    int nx, ny;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cloud[i][j]) {
                cloud[i][j] = false;
                nx = i;
                ny = j;
                for (int k = 0; k < s; k++) {   // s칸 만큼 이동
                    nx += dx[d];
                    ny += dy[d];
                }

                while (nx <= 0) nx += N;
                while (nx > N) nx -= N;
                while (ny <= 0) ny += N;
                while (ny > N) ny -= N;

                tmpCloud[nx][ny] = true;
            }
        }
    }

    memcpy(cloud, tmpCloud, sizeof(tmpCloud));

    // 물의 양 1 증가 & 구름 소멸
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cloud[i][j]) A[i][j]++;
        }
    }

    // 4. 구름의 대각에 물이 있다면 그만큼 증가
    checkCloud();

    // 5. 물의 양이 2 이상인 칸에 구름이 생성
    changeCloudAreaAndCheck();

    memset(tmpCloud, false, sizeof(tmpCloud));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    // 초기 구름 위치
    for (int i = N - 1; i <= N; i++) {
        for (int j = 1; j <= 2; j++) {
            cloud[i][j] = true;
        }
    }

    int d, s;
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        moveCloudAndRain(d, s);
    }

    // 결과
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            answer += A[i][j];
        }
    }

    cout << answer;

    return 0;
}

