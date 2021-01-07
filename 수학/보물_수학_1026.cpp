#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;    // 전체 수의 개수
   
    vector<int> A(N), B(N);

    for (int i = 0; i < N; i ++){
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());   // A 오름차순
    sort(B.rbegin(), B.rend()); // B 내림차순
    
    int res = 0;    
    for (int i = 0; i < N; i++) {
        res += (A[i] * B[i]);
    }
    cout << res;

    return 0;
}