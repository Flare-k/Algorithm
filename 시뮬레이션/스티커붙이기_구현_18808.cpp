#include <iostream>
#include <cstring>
#include <vector>
#define MAX 41
#define R 11
#define C 11
using namespace std;

int N, M, K;
int laptop[MAX][MAX];
int sticker[101][R][C];
int tmp[R][C];
struct Node {
    int r, c;
};
vector<Node> list;

void clockwise(int idx) {
    memset(tmp, 0, sizeof(tmp));
    int r = list[idx].r;
    int c = list[idx].c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[j][r - i - 1] = sticker[idx][i][j];
        }
    }

    memcpy(sticker[idx], tmp, sizeof(sticker[idx]));
    list[idx] = {c, r};
}

bool checkRange(int x, int y, int idx) {
    int r = list[idx].r;
    int c = list[idx].c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[idx][i][j] == 1 && laptop[i + x][j + y] == 1) return false;
        }
    }

    return true;
}

void stickerLaptop(int x, int y, int idx) {
    int r = list[idx].r;
    int c = list[idx].c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[idx][i][j] == 1) {
                laptop[i + x][j + y] = sticker[idx][i][j];
            }
        }
    }
}

int countSticker() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (laptop[i][j] == 1) sum++;
        }
    }

    return sum;
}

void run(int idx) {
    for (int d = 0; d < 4; d++) {
        bool flag = false;
        int r = list[idx].r;
        int c = list[idx].c;

        for (int x = 0; x < N - r + 1; x++) {
            for (int y = 0; y < M - c + 1; y++) {
                if (checkRange(x, y, idx)) {
                    stickerLaptop(x, y, idx);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag) break;
        clockwise(idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int idx = 0; idx < K; idx++) {
        int r, c;
        cin >> r >> c;
        
        list.push_back({r, c});

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[idx][i][j];
            }
        }
    }

    for (int idx = 0; idx < K; idx++) {
        run(idx);
    }

    cout << countSticker() << '\n';
   
    return 0;
}