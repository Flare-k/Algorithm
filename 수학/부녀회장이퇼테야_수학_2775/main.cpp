#include <iostream>
using namespace std;

int getHome(int a, int b) {
   if (b == 1) return 1;
   if (a == 0) return b;
   return (getHome(a - 1, b) + getHome(a, b - 1));
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t, k, n;
   cin >> t;
   for (int i = 0; i < t; i++) {
      cin >> k >> n;
      cout << getHome(k, n) << endl;
   }
   return 0;
}
