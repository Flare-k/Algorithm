#include <algorithm>
#include <iostream>
using namespace std;

int arr[64][64];

void changeDimension(int x, int y, int size) {
    int firstElem = arr[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != firstElem) {
                cout << '(';

                for (int a = 0; a < 2; a++) {
                    for (int b = 0; b < 2; b++) {
                        if (size == 1) {
                            cout << arr[x][y];
                            return;
                        }
                        changeDimension(x + (size / 2) * a, y + (size / 2) * b, size / 2);
                    }
                }
                cout << ')';
                return;
            }
        }
    }

    cout << arr[x][y];
    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        string row = "";
        cin >> row;
        for (int j = 0; j < size; j++) {
            arr[i][j] = (row[j] - '0');
        }
    }

    changeDimension(0, 0, size);

    return 0;
}