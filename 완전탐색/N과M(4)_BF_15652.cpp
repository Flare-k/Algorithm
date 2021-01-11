#include <iostream>
using namespace std;

bool c[10]; int a[10];

void go(int index, int start, int n, int m) {
    if (index == m) {
        for (int j = 0; j < m; j++) {
            cout << a[j] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        if (!c[i]) {
            a[index] = i;
            go(index + 1, i, n, m);
        }
    }
}
/*
 index=0일 때 1 고정, index=1일 때 1~n만큼 반복하고 go에서 나옴.
 이때 index=1 -> 다시 index=0 으로 가야함.
 그리고 나서 i+=1 -> i=2부터 시작.
 */
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;

    go(0, 1, n, m);
    
    return 0;
}
