#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr;

    while (1) {
        arr.clear();
        memset(visit, false, sizeof(visit));

        int num;
        cin >> num;

        if (num == -1) break;

        arr.push_back(num);

        while (1) {
            cin >> num;
            if (num == 0) break;
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end());

        int cnt = 0;
        for (int a : arr) {
            visit[a] = true;
            if (a % 2 == 0 && visit[a / 2]) cnt++;
        }

        cout << cnt << '\n';
    }


    return 0;
}