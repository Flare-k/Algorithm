#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;
/*
 */
vector<long long> ans;
bool cmp(char a, char b) {
   if (a > b) return true;
   return false;
}  // 내림차순정렬

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   string num;
   cin >> num;

   long long sum = 0;
   bool zero = false;

   // 모든 자리의 수를 다 더해서 3의 배수인지 알아보기 위해 sum에 다 더해준다.
   // 자리수 중에 0이 존재하면 30의 배수임을 확인할 수 있다.
   for (int i = 0; i < num.size(); i++) {
      sum += (num[i] - '0');
      if (!(num[i] - '0')) zero = true;
   }
   // 3의 배수가 아니거나 0이 없는 경우
   if (sum % 3 || !zero) {
      cout << -1 << endl;
   } else {
      sort(num.rbegin(), num.rend());
      cout << num << endl;
   }

   return 0;
}