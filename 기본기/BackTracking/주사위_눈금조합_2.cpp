#include <iostream>
using namespace std;

// 주사위는 3개라고 가정. 중복 고려
// 순열

int path[10];
int used[10];

void dice(int level) {
    if (level == 3) {
        for (int i = 0; i < 10; i++) {
            if (path[i]) {
                cout << path[i] << " ";
            }
        }
        cout << '\n';
    
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if (used[i] == 1) continue;

        path[level] = i;
        used[i] = 1;
        dice(level + 1);
        used[i] = 0;
        path[level] = 0;
    }
}

int main() {
    dice(0);

    return 0;
}