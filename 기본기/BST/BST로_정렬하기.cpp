#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tree[100];

void DFS(int node) {
    if (tree[node] == 0) return;

    DFS(node * 2);
    cout << tree[node] << " ";
    DFS(node * 2 + 1);
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    for (int i = 0; i < 6; i++) {
        cin >> n;
        insert(n);
    }
    
    DFS(1);

    return 0;
}