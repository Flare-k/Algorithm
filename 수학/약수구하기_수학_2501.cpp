#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> arr;
    
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) arr.push_back(i);
    }

    if (arr.size() >= K) cout << arr[K - 1];
    else cout << 0;

    return 0;
}