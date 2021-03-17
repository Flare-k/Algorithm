#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second > b.second) return true;
    if (a.second == b.second) {
        if (a.first < b.first) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int board[10][10];
    int bitBoard[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bitBoard[i][j];
        }
    }

    int tmp[10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bitBoard[i][j]) {
                tmp[board[i][j]]++;
            }
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i < 10; i++) {
        if (tmp[i]) {
            ans.push_back({i, tmp[i]}); // {target, cnt}
        }
    }
    
    sort(ans.begin(), ans.end(), cmp);


    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].second; j++) {
            cout << ans[i].first << ' ';
        }
    }

    return 0;
}