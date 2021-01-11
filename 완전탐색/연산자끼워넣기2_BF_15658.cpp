#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[11];
int operate[4];
int sum;
int maxAns = -1000000000;
int minAns = 1000000000;

void go(int sum, int idx, int plus, int minus, int mult, int div) {
    if (idx >= n) {
        if (sum > maxAns)
            maxAns = sum;
        if (sum < minAns)
            minAns = sum;
        return;
    }

    if (plus) go(sum+arr[idx], idx+1, plus-1, minus, mult, div);
    if (minus) go(sum-arr[idx], idx+1, plus, minus-1, mult, div);
    if (mult) go(sum*arr[idx], idx+1, plus, minus, mult-1, div);
    if (div) go(sum/arr[idx], idx+1, plus, minus, mult, div-1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < 4; i++)
        cin >> operate[i];
    
    go(arr[0], 1, operate[0], operate[1], operate[2], operate[3]);
    cout << maxAns << '\n' << minAns << '\n';
    
    return 0;
}
