#include <iostream>
#include <string>
using namespace std;

// 1 ~ N 길이
long long length(int N) {
    /* 1 ~ 9, 10 ~ 99, 100 ~ 999, .. */
    long long len = 0;
    
    for (int start = 1, i = 1; start <= N; start *= 10, ++i) {
        int end = (start * 10) - 1;
        if (end > N) end = N;

        len += (long long)(end - start + 1) * i;
    }

    return len;
}

int binary_search(int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        long long len = length(mid); 
        // 1부터 mid까지 이어붙인 수의 길이 < target이면 [mid + 1, right] 범위에서 재탐색
        if (len < target) left = mid + 1;
        // 1부터 mid까지 이어붙인 수의 길이 >= target 이면 [left, mid - 1] 범위에서 재탐색
        else right = mid - 1;
    }

    return right + 1;
}


int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    if (length(N) < K) {
        cout << -1;
    }
    else {
        int num = binary_search(1, N, K);
        int lenOfNum = length(num);

        string s_num = to_string(num);

        cout << s_num[(s_num.size() - 1 - (lenOfNum - K))];
    }

    return 0;
}