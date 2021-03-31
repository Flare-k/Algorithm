#include <iostream>
using namespace std;

/*
 조합
 눈금이 중복되지 않도록!!
 예, 1 1 2가 나왔다면 1 2 1은 나오면 안 됨
 조합을 구현할 땐 start 파라미터 잊지말 것
*/

int path[10];
int used[10];

void dice(int level, int start) {
    if (level == 3) {
        for (int i = 0; i < 10; i++) {
            if (path[i]) {
                cout << path[i] << " ";
            }
        }
        cout << '\n';
    
        return;
    }

    for (int i = start; i <= 6; i++) {
        path[level] = i;
        dice(level + 1, i);
        path[level] = 0;
    }
}

int main() {
    dice(0, 1);

    return 0;
}
