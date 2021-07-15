#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int num;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }

    vector<int> arr;
    for (int a : s) {
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    for (int a : arr) {
        cout << a << ' ';
    }

    return 0;
}