#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    string str;
    int idx;
};

unordered_map<string, int> m;
vector<Node> v;
vector<Node> ans;

bool cmp(Node a, Node b) {
    if (a.idx < b.idx) return true;
    return false;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t;
   cin >> t;

   while (t--) {
       int n;
       cin >> n;
        
        v.clear();
        m.clear();
        ans.clear();

        string cmd;
        int idx = 1;
        
        for (int j = 0; j < n; j++) {
            cin >> cmd;
            m[cmd] = idx++;
        }

        for (int i = 0; i < n; i++) {
            cin >> cmd;
            v.push_back({cmd, m[cmd]});
        }

        idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> cmd;
            ans.push_back({cmd, v[idx++].idx});
        }

        sort(ans.begin(), ans.end(), cmp);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].str << ' ';
        }

        cout << '\n';

   }

   return 0;
}