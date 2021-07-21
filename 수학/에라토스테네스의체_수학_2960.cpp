#include <iostream>
using namespace std;

const int MAX = 1001;
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 2; i < MAX; i++) {
        arr[i] = i;
    }

    bool flag = false;
    for (int i = 2; i < MAX; i++) {
        if (arr[i] == 0) continue;
        for (int j = i; j <= N; j += i) {
            if (arr[j] == 0) continue;
            K--;

            if (K == 0) {
                cout << arr[j];
                flag = true;
                break;
            }

            arr[j] = 0;
        }

        if (flag) break;
    }

    return 0;
}