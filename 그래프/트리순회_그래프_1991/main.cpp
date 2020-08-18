#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
#define INF 0x7fffffff
#define MAX 1001
using namespace std;

int tree[27][2];
void preorder(int x) {  // 전위순회
   if (x == -1) return;
   cout << (char)(x + 'A');
   preorder(tree[x][0]);
   preorder(tree[x][1]);
}
void inorder(int x) {  // 중위 순회
   if (x == -1) return;
   inorder(tree[x][0]);
   cout << (char)(x + 'A');
   inorder(tree[x][1]);
}
void postorder(int x) {  // 후위 순회
   if (x == -1) return;
   postorder(tree[x][0]);
   postorder(tree[x][1]);
   cout << (char)(x + 'A');
}
int main() {
   int n;
   char x, y, z;
   cin >> n;

   for (int i = 1; i <= n; i++) {
      cin >> x >> y >> z;
      x -= 'A';
      if (y == '.') {
         tree[x][0] = -1;
      } else {
         tree[x][0] = y - 'A';
      }

      if (z == '.') {
         tree[x][1] = -1;
      } else {
         tree[x][1] = z - 'A';
      }
   }
   preorder(0);
   cout << '\n';
   inorder(0);
   cout << '\n';
   postorder(0);
   cout << '\n';
}
