#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;
int n, input, sum = 0;
vector<int> arr;

bool comp(pair<int, int> a, pair<int, int> b) {
   if (a.first > b.first)
      return true;
   else if (a.first == b.first) {
      if (a.second < b.second) return true;
   }
   return false;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> input;
      sum += input;
      arr.push_back(input);
   }
   sort(arr.begin(), arr.end());
   int minN = arr.front();  // arr의 최소값
   int maxN = arr.back();   // arr의 최대값

   int idx = 1;
   int cnt = 1;
   vector<pair<int, int> > res;
   int temp = arr[0];
   while (idx != (arr.size()+1)) {
      if (arr[idx] == temp) {
         cnt++;
      } else {
         res.push_back(make_pair(cnt, temp));  // 횟수와 해당 값 저장
         temp = arr[idx];
         cnt = 1;
      }
      idx++;
   }
   sort(res.begin(), res.end(), comp);
   int ans = 0;
   if (res.size() == 1)
      ans = res[0].second;
   else {
      if (res[0].first == res[1].first)
         ans = res[1].second;
      else
         ans = res[0].second;
   }
   cout << round(sum / (double)n) << endl;  //산술평균
   cout << arr[round(n / 2)] << endl;       //중앙값
   cout << ans << endl;
   cout << maxN - minN << endl;  // 범위

   return 0;
}