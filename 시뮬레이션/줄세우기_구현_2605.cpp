#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr;

    int num;
    int stu = 1;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.insert(arr.begin() + num, stu++);
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }

    return 0;
}