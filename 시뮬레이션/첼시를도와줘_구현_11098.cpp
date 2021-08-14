#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int price;
    string player;
};

vector<Node> list;

bool cmp(Node a, Node b) {
    if (a.price > b.price) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        list.clear();

        int n;
        cin >> n;

        int price;
        string player;

        for (int i = 0; i < n; i++) {
            cin >> price >> player;
            list.push_back({price, player});
        }

        sort(list.begin(), list.end(), cmp);

        cout << list.front().player << '\n';

    }

    return 0;
}