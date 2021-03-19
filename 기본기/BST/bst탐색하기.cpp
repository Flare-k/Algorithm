#include <iostream>
using namespace std;

int tree[100];

void insert(int v) {
    int now = 1;

    while (1) {

        if (tree[now] == 0) {
            tree[now] = v;
            return;
        }

        if (tree[now] < v) {
            now = (now * 2) + 1;
        }
        else {
            now *= 2;
        }
    }
}

int find(int v, int& cnt) {
    int now = 1;

    while (1) {
        if (now > 100 || tree[now] == 0) return 0;

        cnt++;

        if (tree[now] == v) return 1;

        if (tree[now] < v) {
            now = (now * 2) + 1;
        }
        else {
            now *= 2;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    insert(15);
    insert(7);
    insert(19);
    insert(8);
    insert(17);
    insert(25);
    insert(16);
    insert(18);

    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;

        int cnt = 0;
        if (find(n, cnt) == 1) {
            cout << n << ":" << cnt << "회만에찾음\n";
        }
        else {
            cout << n << ":" << "없음\n";
        }
    }

    return 0;
}