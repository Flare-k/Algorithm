#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;

const int MAX = 100000 + 1;
int n, m;
int arr[MAX];

int binarySearch(int num) {
   int first = 0;
   int last = n - 1;
   int mid = 0;

   while (first <= last) {
      mid = (first + last) / 2;

      if (num == arr[mid])
         return 1;
      else {
         if (num < arr[mid])
            last = mid - 1;
         else
            first = mid + 1;
      }
   }
   return 0;
}

void init() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
}
int main() {
   init();
   cin >> n;
   for (int i = 0; i < MAX; i++) {
      arr[i] = 0;
   }
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   sort(arr, arr + n);
   cin >> m;
   int num;
   for (int i = 0; i < m; i++) {
      cin >> num;
      cout << binarySearch(num) << endl;
   }
   return 0;
}