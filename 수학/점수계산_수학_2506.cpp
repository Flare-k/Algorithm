#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    int cnt = 0;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num == 1) {
            cnt++;
            sum += cnt;
        }
        else {
            cnt = 0;
        }
    }

    cout << sum;

    return 0;
}