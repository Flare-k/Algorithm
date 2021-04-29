#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> check;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> sinker(n);

    for (int i = 0; i < n; i++) {
        cin >> sinker[i];
    }

    sort(sinker.begin(), sinker.end());

    int sum = 1;
    for (int i = 0; i < sinker.size(); i++) {
        if (sinker[i] > sum) break;

        sum += sinker[i];
    }

    cout << sum;

    return 0;
}