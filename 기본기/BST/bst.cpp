#include <iostream>
using namespace std;

int vec[100];

void insert(int v) {
    int now = 1;

    while (1) {
        if (vec[now] == 0) {
            vec[now] = v;
            break;
        }

        if (vec[now] < v) now = now * 2 + 1;
        else now *= 2;
    }
}

int find(int v) {
    int now = 1;

    while (1) {
        if (vec[now] == v) return 1;
        if (vec[now] == 0) return 0;

        if (vec[now] < v) now = now * 2 + 1;
        else now *= 2;
    }
}

int main() {

    insert(4);
    insert(2);
    insert(5);
    insert(9);
    insert(15);

    if (find(6)) {
        cout << "트리에 있습니다.";
    }
    else {
        cout << "트리에 없습니다.";
    }
}