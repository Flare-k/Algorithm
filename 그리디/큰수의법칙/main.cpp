#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 다양한 수로 이루어진 배열이 있을 때 주어진 수들을 M번 더하여 가장 큰 수를
만드는 법칙이다. 단, 배열의 특정한인덱스(번호)에 해당하는 수가 연속해서 K번을
초과하여 더해질 수 없는 것이 이 법칙의 특징이다.

 가장 큰 수와 두번째로 큰 수를 따로 할당해두어 큰수를 K번 더하고 두번째 큰 수를
한 번만 더하는 방식을 채택한다.

<입력>
5 8 3
2 4 5 4 6

<출력>
46
*/

int first = 0;
int second = 0;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n, m,
       k;  // n=총 배열의 개수, m=연산하기 위한 개수, k=최대로 더할 수 있는 개수
   cin >> n >> m >> k;
   vector<int> arr;
   for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      arr.push_back(a);
   }
   sort(arr.begin(), arr.end());
   first = arr[n - 1];
   second = arr[n - 2];

   int sum = 0;
   int cnt = 0;
   while (m--) {
      if (cnt == 3) {
         sum += second;
         cnt = 0;
      } else {
         sum += first;
      }

      cnt++;
   }

   cout << sum << endl;

   return 0;
}