#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int paper[MAX][MAX];
int stickerCnt;
int d[6] = {0, 5, 5, 5 ,5, 5};
int answer = 21e8;
enum {
    EMPTY, STICKER
};

bool possible(int x, int y, int size) {
    if (x + size > MAX || y + size > MAX || d[size] == 0) return false;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] == EMPTY) return false;
        }
    }
    return true;
}

void checkSticker(int x, int y, int size, int sticker) {
    if (sticker == 0) {
        d[size]--;
        stickerCnt -= size * size;
    }
    else {
        d[size]++;
        stickerCnt += size*size;
    }

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            paper[i][j] = sticker;
        }
    }

}

void run(int level, int x, int y) {
    if (stickerCnt == 0) {
        answer = min(answer, level);
        return;
    }

    for (int i = x; i < MAX; i++) {
        for (int j = y; j < MAX; j++) {
            if (paper[i][j] == STICKER) {
                for (int size= 5; size >= 1; size--) {
                    if (possible(i, j, size)) {
                        checkSticker(i, j, size, 0);
                        run(level + 1, i, j + size);
                        checkSticker(i, j, size, 1);
                    }
                }

                return;
            }
        }

        y = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> paper[i][j];
            if (paper[i][j] == STICKER) stickerCnt++;
        }
    }

    bool flag = false;

    if (stickerCnt == MAX * MAX) {
        cout << 4 << '\n';
        flag = true;
    }
    else run(0, 0, 0);

    if (!flag) {
        if (answer == 21e8) cout << -1 << '\n';
        else cout << answer << '\n';
    }

    return 0;
}