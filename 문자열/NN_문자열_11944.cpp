#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    string num = to_string(N);
    int len = num.length();

    int iter = min(len * N, M); // 길이만큼 N번 or M 자리

    for (int i = 0; i < iter; i++) {
        cout << num[i % len];
    }

    return 0;
}