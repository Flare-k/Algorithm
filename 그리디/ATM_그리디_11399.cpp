#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n;
   cin >> n;
   vector<int> minutes;
   int a;  // 각 사람의 인출 시간
   for (int i = 0; i < n; i++) {
      cin >> a;
      minutes.push_back(a);
   }
   sort(minutes.begin(), minutes.end());    // ATM 사용시간을 오름차순 정렬한다.
   int sum = 0;
   sum += minutes[0];
   for (int i = 1; i < minutes.size(); i++) {
      minutes[i] += minutes[i - 1]; // 각 사용시간의 누적의 합을 구해야하므로 이전 사람의 시간만큼 각각 더해준다.
      sum += minutes[i];
   }

   cout << sum;

   return 0;
}