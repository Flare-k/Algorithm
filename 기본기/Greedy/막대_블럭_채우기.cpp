#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> blocks;

    int block;
    for (int i = 0; i < n; i++) {
        cin >> block;
        blocks.push_back(block);
    }

    sort(blocks.begin(), blocks.end());

    int limit = 100;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (limit - blocks[i] >= 0) {
            limit -= blocks[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
/*
6
20 57 13 40 33 8
> 4

6
50 40 10 5 15 30
> 5
*/