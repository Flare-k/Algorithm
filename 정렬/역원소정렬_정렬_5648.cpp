#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string str;
    vector<long long> v;

    for (int i = 0; i < N; i++) {
        cin >> str;
        reverse(str.begin(), str.end());

        long long num = stoll(str);
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}