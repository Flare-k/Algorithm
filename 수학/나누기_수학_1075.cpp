#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, F;
    cin >> N >> F;

    // 끝 두자리를 하나씩 올려가며 나눠떨어지는 것을 확인하기 위해 두자리를 00으로 갱신
    int start = (N / 100) * 100;

    while (start % F != 0) {
        start++;
    }

    // 끝 두자리를 할당
    int res;
    res = start % 100;

    if (res >= 0 && res < 10) {
        cout << 0;
    }
    cout << res;

    return 0;
}