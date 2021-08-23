#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 9;
int sudoku[MAX][MAX];
int row[MAX][MAX];
int col[MAX][MAX];
int smallbox[MAX][MAX];

void run(int cnt) {

    int x = cnt / MAX;
    int y = cnt % MAX;

    if (cnt == 81) {
        for (int i = 0 ; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    if (sudoku[x][y] == 0) {
        for (int i = 1; i <= MAX; i++) {
            if (!row[x][i] && !col[y][i] && !smallbox[(x / 3) * 3 + (y / 3)][i]) {
                row[x][i] = true;
                col[y][i] = true;
                smallbox[(x / 3) * 3 + (y / 3)][i] = true;
                sudoku[x][y] = i;
                
                run(cnt + 1);
                
                sudoku[x][y] = 0;
                smallbox[(x / 3) * 3 + (y / 3)][i] = false;
                col[y][i] = false;
                row[x][i] = false;

            }
        }
    }
    else {
        run(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];

            if (sudoku[i][j] != 0) {
                row[i][sudoku[i][j]] = true;    // i 행에 숫자 x가 있다.
                col[j][sudoku[i][j]] = true;    // j 열에 숫자 x가 있다.
                smallbox[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true; // 작은 사각형에 숫자 x가 있다.
            }
        }
    }

    run(0);
    

    return 0;
}