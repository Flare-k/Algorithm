#include <iostream>
using namespace std;

/*
  A B C 세장의 카드를 이용해 만들 수 있는 순열은?
  같은 알파벳 카드는 등장하지 않는다.
*/

char path[4];
int used[4];

void shuffle(int level, char card[]) {
    if (level == 3) {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (used[i] == 1) continue;

        path[level] = card[i];
        used[i] = 1;
        shuffle(level + 1, card);
        used[i] = 0;
        path[level] = 0;
    }
}

int main() {
    char card[4];

    for (int i = 0; i < 3; i++) {
        cin >> card[i];
    }

    shuffle(0, card);

    return 0;
}