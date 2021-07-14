#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    LIS
    가장 큰 증가하는 부분수열
    O(nlogn) 방법
    https://jason9319.tistory.com/113 참고
    이분탐색 이용
*/

vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    arr.push_back(-987654321);

    int num;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (arr.back() < num) {
            arr.push_back(num);
            answer++;
        }
        else {
            auto it = lower_bound(arr.begin(), arr.end(), num);
            *it = num;
        }
    }

    cout << n - answer;

    return 0;
}