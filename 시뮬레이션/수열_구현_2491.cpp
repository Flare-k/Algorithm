#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int hcnt = 1, lcnt = 1;
    int maxx = -1;

    for (int i = 0; i < n - 1; i++) {
        // 증가하는 수열
        if (arr[i] <= arr[i + 1]) hcnt++;
        else {
            if (hcnt >= 2) maxx = max(maxx, hcnt);
            hcnt = 1;
        }

        // 감소하는 수열
        if (arr[i] >= arr[i + 1]) lcnt++;
        else {
            if (lcnt >= 2) maxx = max(maxx, lcnt);
            lcnt = 1;
        }
    }
    
    maxx = max(maxx, hcnt);
    maxx = max(maxx, lcnt);

    cout << maxx;

    return 0;
}