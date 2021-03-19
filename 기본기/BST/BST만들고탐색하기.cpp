#include <iostream>
using namespace std;

int tree[100];

void insert(int v, int now) {
    if (tree[now] == 0) {
        tree[now] = v;
        return;
    }

    if (tree[now] < v) {
        insert(v, now * 2 + 1);
    }
    else {
        insert(v, now * 2);
    }
}

char find(int v, int now) {
    if (now > 100 || tree[now] == 0) return 'X';
    if (tree[now] == v) return 'O';

    char ans;

    if (tree[now] < v) {
        ans = find(v, now * 2 + 1);
    }
    else if (tree[now] > v) {
        ans = find(v, now * 2);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        insert(num, 1);
    }

    for (int i = 1; i <= 6; i++) {
        cout << i << ":" << find(i, 1) <<"\n";
    }

    return 0;
}