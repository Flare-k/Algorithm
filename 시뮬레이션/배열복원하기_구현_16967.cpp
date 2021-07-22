#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 610;
int H, W, X, Y;
int arrB[MAX][MAX];
int arrA[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(arrA, 0, sizeof(arrA));
    memset(arrB, 0, sizeof(arrB));

    cin >> H >> W >> X >> Y;

    int NX = H + X;
    int NY = W + Y;

    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            cin >> arrB[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            arrA[i][j] = arrB[i][j];
        }
    }

    for (int i = X; i < H; i++) {
        bool flag = false;
        for (int j = Y; j < NY; j++) {
            if (arrA[i][j] != 0) 
            arrA[i][j] -= arrA[i - X][j - Y];
            flag = true;
        }
        if (!flag) break;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << arrA[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

