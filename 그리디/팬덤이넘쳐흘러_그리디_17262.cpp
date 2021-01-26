#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int start[100001];
    int end[100001];

    int minNum = 987654321;
    int maxNum = 0;

    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];

        maxNum = max(maxNum, start[i]);
        minNum = min(minNum, end[i]);
    }

    int gap = maxNum - minNum;

    if (gap < 0)
        cout << 0;
    else
        cout << gap;

    return 0;
}