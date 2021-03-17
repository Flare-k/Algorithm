#include <iostream>
#include <cstring>
using namespace std;

int lh[4][8];

int check(int i, int j, int x, int y) {
    int sum = 0;

    for (int row = i; row <= x; row++) {
        for (int col = j; col <= y; col++) {
            if (lh[row][col] == 0) return -1;
            sum += lh[row][col];
        }
    }

    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(lh, 0, sizeof(lh));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> lh[i][j];
        }
    }


    int max = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (lh[i][j] > 0) {
                
                for (int x = i; x < 4; x++) {
                    for (int y = j; y < 8; y++) {
                        if (lh[x][y] > 0) {
                            int res = check(i, j, x, y);

                            if (res != -1) {
                                if (max < res) {
                                    max = res;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max;

    return 0;
}