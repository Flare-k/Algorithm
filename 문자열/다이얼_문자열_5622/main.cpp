#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

// 다이얼을 당기려면 문자열의 길이만큼 초가 더 추가된다.

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int dial[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6,
                   6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
   string word;

   cin >> word;
   int sum = 0;
   for (int i = 0; i < word.length(); i++) {
      if (word[i] == '1') {
         sum += 1;
      } else if (word[i] == '0') {
         sum += 10;
      } else
         sum += dial[int(word[i]) - 65];
   }
   sum += word.length();
   cout << sum;

   return 0;
}
/*
a = 97
A = 65
32차이
*/