#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int score, idx;
};

bool cmp(Node a, Node b) {
    if (a.score < b.score) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<Node> arr;

    int num;
    for (int i = 0; i < 8; i++) {
        cin >> num;
        arr.push_back({num, i + 1});
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<int> res;
    int totalScore = 0;
    for (int i = 3; i < 8; i++) {
        totalScore += arr[i].score;
        res.push_back(arr[i].idx);
    }

    sort(res.begin(), res.end());

    cout << totalScore << '\n';
    for (int i = 0; i < 5; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}