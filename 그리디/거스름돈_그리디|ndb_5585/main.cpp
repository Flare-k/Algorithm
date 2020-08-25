#include <iostream>
using namespace std;
/*
    그리디 알고리즘으로 해결할 수 있는 이유?
    가지고 있는 동전 중에서 큰 단위가 항상 작은 단위의 배수이므로 작은 단위의
   동전들을 종합해 다른 해가 나올 수 없기 때문이다.
   하지만 최적의 해를 찾을 수 없을 가능성이 다분하다.
*/
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin >> n;
   n = 1000 - n;
   int count = 0;

   int arr[6] = {500, 100, 50, 10, 5, 1};

   for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
      count += (n / arr[i]);
      n %= arr[i];
   }
   cout << count << endl;
   return 0;
}