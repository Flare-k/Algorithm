#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr(3);

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    string apb;
    cin >> apb;

    int idx = 0;
    for (int num : arr) {
        m['A' + idx++] = num;
    }

    for (char ch : apb) {
        cout << m[ch] << ' ';
    }

    return 0;
}