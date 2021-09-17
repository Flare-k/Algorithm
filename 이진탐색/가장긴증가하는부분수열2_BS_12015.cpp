#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int maxx = -21e8;
    vector<int> v;
    v.push_back(maxx);
    
    int cnt = 0, num;

    for (int i = 0; i < N; i++) {
        cin >> num;

        if (v.back() < num) {
            v.push_back(num);
            cnt++;
        }
        else {
            auto iter = lower_bound(v.begin(), v.end(), num);
            *iter = num;
        }
    }

    cout << cnt;

    return 0;
}