#include <iostream>
using namespace std;

// 주사위는 3개라고 가정. 중복 고려 X

int path[10];

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

    for (int i = 0; i < 6; i++) {
        path[level] = i + 1;
        dice(level + 1);
        path[level] = 0;
    }
}

int main() {

    dice(0);

    return 0;
}