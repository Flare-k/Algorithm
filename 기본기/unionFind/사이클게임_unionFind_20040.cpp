#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500001;
int arr[MAX];

int getBoss(int num) {
    if (arr[num] == -1) return num;

    int res = getBoss(arr[num]);
    arr[num] = res;

    return res;
}

void setGroup(int n1, int n2) {
    int g1 = getBoss(n1);
    int g2 = getBoss(n2);

    if (g1 == g2) return;
    arr[g2] = g1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(arr, arr + MAX, -1);

    int n, m;
    cin >> n >> m;

    bool flag = false;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (getBoss(a) == getBoss(b)) {
            cout << i + 1;
            flag = true;
            break;
        }

        setGroup(a, b);
    }

    if (!flag) {
        cout << 0;
    }
    return 0;
}