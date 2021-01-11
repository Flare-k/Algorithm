#include <iostream>
#include <algorithm>
using namespace std;

/**
 * (1) 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
 * (2) (1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
*/
int arr[2188][2188];

void devidePaper(int x, int y, int size, int res[3]) {
    int firstElem = arr[x][y];
    bool flag = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != firstElem) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        // -1, 0, 1
        res[firstElem + 1]++;
    }
    else {
        for (int nx = x; nx < x + size; nx += size/3) {
            for (int ny = y; ny < y + size; ny += size/3) {
                devidePaper(nx, ny, size/3, res);
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    int res[3];
    fill(res, res + 3, 0);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }

    devidePaper(0, 0, size, res);

    for (int i = 0; i < 3; i++) {
        cout << res[i] << endl;
    }

    return 0;
}