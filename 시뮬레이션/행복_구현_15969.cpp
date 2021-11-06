#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int maxScore = -21e8;
   int minScore = 21e8;

   int n;
   cin >> n;

   for (int i = 0; i < n; i++) {
       int score;
       cin >> score;

       maxScore = max(score, maxScore);
       minScore = min(score, minScore);
   }

   cout << maxScore - minScore;

   return 0;
}