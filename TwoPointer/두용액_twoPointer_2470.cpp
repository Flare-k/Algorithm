#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long mix = 0;
    int start = 0;
    int end = arr.size() - 1;
    int left = 0;
    int right = 0;
    int minGap = 21e8;

    while (1) {
        if (start >= end) break;

        mix = arr[start] + arr[end];

        if (llabs(mix) < minGap) {
            minGap = llabs(mix);
            left = arr[start];
            right = arr[end];
        }

        if (mix < 0) {
            start++;
        }
        else {
            end--;

        }
    }

    cout << left << " " << right;

    return 0;
}

/*
7
-99 -2 -1 1 98 100 101
> -1, 1

5
1 2 3 4 5
> 1, 2

5
-1 -2 -3 -4 -5
> -1, -2

6
-99 -60 3 7 61 130
> -60, 61

*/