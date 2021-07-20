#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int L, P;
    cin >> L >> P;

    int W = L * P;

    int num;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        cout << num - W << ' ';
    }

    return 0;
}