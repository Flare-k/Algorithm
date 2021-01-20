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

bool comp(pair<string, int> a, pair<string, int> b) {
   if (a.second < b.second)
      return true;
   else if (a.second == b.second)
      if (a.first < b.first) return true;
   return false;
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin >> n;
   vector<pair<string, int> > arr;
   while (n--) {
      string s;
      cin >> s;
      arr.push_back(make_pair(s, s.length()));
   }
   sort(arr.begin(), arr.end(), comp);
   string temp;
   for (int i = 0; i < arr.size(); i++) {
      if (arr[i].first == temp) continue;
      cout << arr[i].first << endl;
      temp = arr[i].first;
   }
   return 0;
}