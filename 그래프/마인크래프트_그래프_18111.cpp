#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 501;
int arr[MAX][MAX];
int r, c, b;
int leastTime = 21e8;
int mostH;
int start = 21e8;
int endd = -21e8;
int time = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> b;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            start = min(start, arr[i][j]);
            endd = max(endd, arr[i][j]);
        }
    }

    for (int k = start; k <= endd; k++) {
        int removeBlock = 0;
        int build = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int height = arr[i][j] - k;

                if (height > 0) removeBlock += height;   // 블록을 제거해야하는 경우
                else if (height < 0) build -= height;    // 블록을 채워야하는 경우
            }
        }

        // 제거하거나 채우는 과정에서 인벤토리가 바닥나지 않는다면..
        if (removeBlock + b >= build) {
            time = removeBlock * 2 + build;
            if (leastTime >= time) {
                leastTime = time;
                mostH = k;
            }
        }
    }

    cout << leastTime << ' ' << mostH;

    return 0;
}