#include <iostream>

using namespace std;

int cnt;
int path[10];
int used[10];

// 더해서 10이 되는 경우 모두 출력. 단, 중복되는 숫자는 제외!

void run(int level, int sum) {

    if (level == 4) {
        if (sum == 10) {
            for (int i = 0; i < level; i++) {
                if (i != level - 1) {
                    cout << path[i] << " + ";
                }
                else {
                    cout << path[i] << " = " << sum;
                }
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        if (sum + i > 10) continue;
        if (used[i] == 1) continue;

        used[i] = 1;
        path[level] = i;
        run(level + 1, sum + i);
        path[level] = 0;
        used[i] = 0;
    }
}

int main() {

    run(0, 0);

    return 0;
}