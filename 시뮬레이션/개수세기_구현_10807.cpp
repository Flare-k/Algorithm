#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int arr[101];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == target) cnt++;
    }

    cout << cnt;

    return 0;
}