#include <iostream>
using namespace std;

int tree[100];

void DFS(int now) {
    if (now > 100 || tree[now] == 0) return;

    DFS(now * 2);
    DFS(now * 2 + 1);
    cout << tree[now] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    tree[1] = 3;
    tree[2] = 2;
    tree[3] = 5;
    tree[4] = 1;
    tree[5] = 6;
    tree[7] = 7;
    tree[14] = 4;
    tree[15] = 8;

    DFS(1);
    
    return 0;
}