/* Divide and Conquer */
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n;
const int MAX = 129;
int arr[MAX][MAX];
int w_cnt = 0, b_cnt = 0;

void div_conq(int x, int y, int N) {
    int tmp_cnt = 0;

    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (arr[i][j]) {
                tmp_cnt++;
            }
        }
    }

    if (!tmp_cnt)
        w_cnt++;  // no count
    else if (tmp_cnt == N * N)
        b_cnt++;  // all count
    else {
        div_conq(x, y, N / 2);                  // left top
        div_conq(x, y + N / 2, N / 2);          // right top
        div_conq(x + N / 2, y, N / 2);          // left bottom
        div_conq(x + N / 2, y + N / 2, N / 2);  // right bottom
    }

    return;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    div_conq(0, 0, n);

    cout << w_cnt << "\n" << b_cnt;
    
    return 0;
}
