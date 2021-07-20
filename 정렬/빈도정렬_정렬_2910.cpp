#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int elem, cnt, idx;
};

map<int, Node> m;
vector<Node> arr;

bool cmp(Node a, Node b) {
    if (a.cnt > b.cnt) return true;
    else if (a.cnt == b.cnt) {
        return a.idx < b.idx;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, C;
    cin >> N >> C;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (m.count(num) == false) {
            m[num] = {num, 1, i};
        }
        else {
            m[num].cnt++;
        }
    }

    for (auto i = m.begin(); i != m.end(); ++i) {
        arr.push_back(i->second);
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].cnt; j++) {
            cout << arr[i].elem << ' ';
        }
    }

    return 0;
}