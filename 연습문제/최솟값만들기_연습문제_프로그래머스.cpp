#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < A.size(); i++) {
        answer += (A[i] * B[i]);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution({1, 4, 2}, {5, 4, 4}) << '\n';
    cout << solution({1, 2}, {3, 4}) << '\n';

    return 0;
}