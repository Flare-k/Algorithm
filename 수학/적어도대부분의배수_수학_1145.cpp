#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int idx = arr.front();

    while (1) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (idx % arr[i] == 0) {
                cnt++;

                if (cnt >= 3) {
                    cout << idx << '\n';
                    return 0;
                }
            }
        }

        idx++;
    }

    return 0;
}