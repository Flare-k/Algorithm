#include <iostream>
using namespace std;

int arr[3][3];
bool visit[3][3];
int maxNum = -21e8;
int cnt = 0;

void run(int level, int num, int x, int y) {
    if (level == 3) {
        if (maxNum == num) cnt++;
        if (maxNum < num) {
            cnt = 1;
            maxNum = num;
        }
        return;
    }

    bool flag = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (flag == false) {
                flag = true;
                i = x;
                j = y;
            }

            if (visit[i][j]) continue;

            visit[i][j] = true;
            run(level + 1, num * arr[i][j], i, j);
            visit[i][j] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    run(0, 1, 0, 0);
    
    cout << maxNum << '\n';
    cout << cnt << "번" << '\n';

    return 0;
}
/*
-4 1 3
3 -1 4
-3 4 0

3 -3 5
3 -3 5
1 -5 3

*/