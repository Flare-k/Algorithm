#include <iostream>
#include <cstring>
using namespace std;

// 3514 -> 1293이 되는 경우를 찾아라
// 자신과 양옆의 수가 1씩 감소

char start[4] = {3, 5, 1, 4};
char target[4] = {1, 2, 9, 3};

struct Node {
    char level;
    char number[4]; // 메모리 줄이기 위해 int말고 의도적으로 char 사용
};

Node q[1000000];
int head;
int tail = 1;

void init() {
    q[0].level = 0;
    memcpy(q[0].number, start, 4);
}

void cal(char num[4], int idx) {
    char tmp[6] = {0};
    memcpy(&tmp[1], num, 4);    // 1번째부터 4칸 copy.. 즉, 0번째와 마지막번째는 더미

    for (int i = -1; i <= 1; i++) {
        tmp[idx + 1 + i]--; // 1번째부터이므로 +1을 해준다.
        if (tmp[idx + 1 + i] < 0) tmp[idx + 1 + i] = 9;
    }

    memcpy(num, &tmp[1], 4);
}

bool isTarget(char num[4]) {
    for (int i = 0; i < 4; i++) {
        if (num[i] != target[i]) return false;
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            Node next = now;

            next.level += 1;
            cal(next.number, i);

            q[tail++] = next;

            if (isTarget(next.number) == true) {
                cout << (int)(next.level);
                return 0;
            }
        }
    }

    return 0;
}