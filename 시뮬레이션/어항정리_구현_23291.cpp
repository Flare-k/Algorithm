#include <iostream>
#include <cstring>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
int N, K;
const int MAX = 101;
bool check[MAX][MAX][MAX][MAX];
int fish[MAX][MAX];
int acc[MAX][MAX];
int tmpFish[MAX][MAX];

void putFishInMinBowl() {
    int minn = 21e8;
    for (int j = 1; j <= N; j++) {
        if (fish[N][j] < minn) minn = fish[N][j];
    }

    for (int j = 1; j <= N; j++) {
        if (fish[N][j] == minn) fish[N][j]++;
    }
}

void floatFishBowl1() {
    int start = 1, width = 1, height = 1;
    int idx = 0;

    while (1) {
        if (start + width + height - 1 > N) break;

        for (int j = start; j < start + width; j++) {
            for (int i = N; i > N - height; i--) {
                int nx, ny;

                nx = N - start - width + j;
                ny = N + start + width - i;

                fish[nx][ny] = fish[i][j];
                fish[i][j] = 0;
            }
        }

        if (idx % 2 == 1) width++;
        else height++;

        start += (idx / 2 + 1);
        idx++;
    }
}

void controlFish() {
    memset(acc, 0, sizeof(acc));
    memset(check, false, sizeof(check));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (fish[i][j] == 0) continue;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (check[i][j][nx][ny] && check[nx][ny][i][j]) continue;
                if (fish[nx][ny] == 0) continue;

                check[i][j][nx][ny] = true;
                check[nx][ny][i][j] = true;

                int sub = abs(fish[i][j] - fish[nx][ny]) / 5;

                if (sub > 0) {
                    if (fish[i][j] < fish[nx][ny]) {
                        acc[i][j] += sub;
                        acc[nx][ny] -= sub;
                    }
                    else if (fish[i][j] > fish[nx][ny]) {
                        acc[i][j] -= sub;
                        acc[nx][ny] += sub;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            fish[i][j] += acc[i][j];
        }
    }
}

void initFishBowl() {
    memset(tmpFish, 0, sizeof(tmpFish));
    int idx = 1;
    for (int j = 1; j <= N; j++) {
        for (int i = N; i >= 1; i--) {
            if (fish[i][j] == 0) continue;
            
            tmpFish[N][idx++] = fish[i][j];
        }
    }

    memcpy(fish, tmpFish, sizeof(fish));
}

void floatFishBowl2() {
    int h = (N / 2) + 1;
    
    // 첫 번째 접기
    for (int j = N / 2; j >= 1; j--) {
        fish[N - 1][h++] = fish[N][j];
        fish[N][j] = 0;
    }

    // 두 번째 접기
    for (int i = N - 1; i <= N; i++) {
        int end = (N / 4) * 3;
        int fix = N;

        for (int j = (N / 2) + 1; j <= end; j++) {
            int nx, ny;

            nx = (2 * N) - (i + 3);
            ny = fix--;

            fish[nx][ny] = fish[i][j];
            fish[i][j] = 0;
        }
    }
}

bool checkFish() {
    int maxx = -21e8;
    int minn = 21e8;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (fish[i][j] == 0) continue;
            if (fish[i][j] < minn) minn = fish[i][j];
            if (fish[i][j] > maxx) maxx = fish[i][j];
        }
    }

    if (maxx - minn <= K) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    // 물고기가 가장 많이 들어있는 어항과 가장 적게 들어있는 어항의 물고기 수
    // 차이가 K 이하가 되려면 어항을 몇 번 정리해야하는지 출력

    for (int j = 1; j <= N; j++) {
        cin >> fish[N][j];
    }

    int cnt = 0;

    while (1) {
        putFishInMinBowl();

        floatFishBowl1();
        controlFish();
        initFishBowl();
        
        floatFishBowl2();
        controlFish();
        initFishBowl();

        cnt++;

        if (checkFish()) break;
    }

    cout << cnt;

    return 0;
}