#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int a, b;
    int diff;
};

bool cmp(Node a, Node b) {
    if (a.diff < b.diff) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Node> node;
    vector<string> str;
    vector<int> index;
    
    for (int i = 0; i < n; i++) {
        index.push_back(i * 5);
    }

    string s;
    for (int i = 0; i < n * 5; i++) {
        cin >> s;
        str.push_back(s);
    }


// 0-4 : 5-9 & 10-14 | 5-9 : 10-14
    for (int i = 0; i < index.size() - 1; i++) {
        int iter = index.size() - (i + 1);
        int idx = i + 1;

        while (iter--) {
            int start = index[i];
            int cnt = 0;

            for (int j = index[idx]; j < index[idx] + 5; j++) {
                for (int k = 0; k < 7; k++) {
                    if (str[start][k] != str[j][k]) cnt++;
                }
                start++;
            }

            node.push_back({i + 1, idx + 1, cnt});
            idx++;
        }
    }

    sort(node.begin(), node.end(), cmp);

    cout << node.front().a << ' ' << node.front().b << '\n';

    return 0;
}