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

    for (int i = 1; ; i++) {
        int cnt = 0;
        
        for (int j = 0; j < 5; j++) {
            if (i % arr[j] == 0) {
                cnt++;
                if (cnt >= 3) {
                    cout << i;
                    return 0;
                }
            }
        }
    }

    return 0;
}