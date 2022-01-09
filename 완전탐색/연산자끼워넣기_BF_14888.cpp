#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, num;
vector<int> arr;
vector<int> oper;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    arr.resize(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= 4; i++) {
        cin >> num;

        for (int j = 0; j < num; j++) {
            oper.push_back(i);
        }
    }

    int _max = -21e8;
    int _min = 21e8;

    do {
        int answer = arr.front();

        for (int i = 1; i < arr.size(); i++) {
            int _oper = oper[i - 1];

            if (_oper == 1) answer += arr[i];
            else if (_oper == 2) answer -= arr[i];
            else if (_oper == 3) answer *= arr[i];
            else answer /= arr[i];
        }

        _max = max(_max, answer);
        _min = min(_min, answer);
        
    } while (next_permutation(oper.begin(), oper.end()));

    cout << _max << '\n' << _min;

    return 0;
}