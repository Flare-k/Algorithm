#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
   if (a.second == b.second)
      return a.first < b.first;
   else
      return a.second < b.second;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n;
   vector<pair<int, int> > arr;
   cin >> n;
   for (int i = 0; i < n; i++) {
      int startTime, endTime;
      cin >> startTime >> endTime;
      arr.push_back(make_pair(startTime, endTime));
   }
   sort(arr.begin(), arr.end(), comp);
   int pivot;
   vector<int> ans;
   pivot = arr[0].second;
   int cnt = 1;
   for (int j = 1; j < n; j++) {
      if (pivot <= arr[j].first) {
         pivot = arr[j].second;
         cnt++;
      }
   }
   cout << cnt;
   return 0;
}