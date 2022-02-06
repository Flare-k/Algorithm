#include <iostream>
#define MAX 101
using namespace std;

int H, W;
int map[MAX][MAX];
int answer[MAX][MAX];

void run() {
    for (int i = 0; i < H; i++) {
        int cloud = 0;
        bool flag = false;
        for (int j = 0; j < W; j++) {
            if (map[i][j] == 1) {
                cloud = j;
                answer[i][j] = 0;
                flag = true;
            }
            else if (map[i][j] == 0) {
                if (j - cloud > 0 && flag) answer[i][j] = j - cloud;
                else answer[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}

void init() {
    cin >> H >> W;
    
    char ch;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> ch;
            if (ch == '.') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    run();

    return 0;
}