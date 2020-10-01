#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
const int MAX = 10001;
bool check[MAX];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int temp, sum;

   for (int i = 1; i < MAX; i++) {
      temp = 0;
      sum = 0;
      temp = i;
      while (temp) {
         sum += temp % 10;
         temp /= 10;
      }
      sum += i;
      if (sum <= MAX) check[sum] = true;
   }
   for (int i = 1; i < MAX; i++) {
      if (!check[i]) cout << i << endl;
   }

   return 0;
}