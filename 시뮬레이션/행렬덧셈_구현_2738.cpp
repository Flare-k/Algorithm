#include <iostream>
using namespace std;

int arr[101][101];
int ops[101][101];
int res[101][101];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> ops[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            res[i][j] = arr[i][j] + ops[i][j];
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}