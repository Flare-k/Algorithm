#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int x, y, w, h;
   cin >> x >> y >> w >> h;
   int up, down, left, right;
   up = h - y;
   down = y;
   left = x;
   right = w - x;
   ans.push_back(up);
   ans.push_back(down);
   ans.push_back(left);
   ans.push_back(right);
   sort(ans.begin(), ans.end());
   cout << ans.front();

   return 0;
}