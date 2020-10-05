#include <iostream>
#include <queue>
#include <stack>
#define endl "\n"
using namespace std;
int n, num;
stack<int> s;
queue<int> q;
queue<char> ans;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> num;
      q.push(num);
   }
   int idx = 1;
   while (!q.empty()) {
      if (s.size() && s.top() == q.front()) {
         s.pop();
         q.pop();
         ans.push('-');
      } else if (idx <= q.front()) {
         while (idx <= q.front()) {
            s.push(idx++);
            ans.push('+');
         }
      } else {
         cout << "NO";
         return 0;
      }
   }
   while (!ans.empty()) {
      cout << ans.front() << endl;
      ans.pop();
   }
   return 0;
}