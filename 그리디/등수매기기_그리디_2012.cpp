#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> rank;
    
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        rank.push_back(num);
    }

    sort(rank.begin(), rank.end());

    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += abs(i - rank[i - 1]);
    }

    cout << sum;

    return 0;
}