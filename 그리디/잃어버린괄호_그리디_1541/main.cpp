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

bool change = false;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   string exprs;
   getline(cin, exprs);
   string temp = "";
   int sum = 0;

   for (int i = 0; i <= exprs.size(); i++) {
      if (exprs[i] == '+' || exprs[i] == '-' || exprs[i] == '\0') {
         if (change)
            sum -= stoi(temp);
         else
            sum += stoi(temp);
         if (exprs[i] == '-') change = true;

         temp = "";
         continue;  // 밑에 줄로 내려가지 않게 하기 위해
      }
      temp += exprs[i];
   }
   cout << sum;
   return 0;
}