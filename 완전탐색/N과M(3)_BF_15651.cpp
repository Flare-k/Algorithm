#include <iostream>
using namespace std;

bool c[10]; 
int a[10];

void go(int index, int n, int m) {
    if (index == m) {
        for (int j = 0; j < m; j++) {
            cout << a[j] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!c[i]) {
            a[index] = i;
            go(index+1, n, m);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    go(0, n, m);

    return 0;
}
