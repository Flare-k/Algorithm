#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define erdl "\n"
using namespace std;
vector<int> wheel[4];
vector<pair<int, int> > cmd;

void orthodromic(int n, int d) {  // 정방향
   if (d == 1) {                  // 시계방향
      int tmp = wheel[n][7];
      for (int i = 7; i > 0; i--) {
         wheel[n][i] = wheel[n][i - 1];
      }
      wheel[n][0] = tmp;
   } else if (d == -1) {  // 반시계방향
      int tmp = wheel[n][0];
      for (int i = 0; i < 7; i++) {
         wheel[n][i] = wheel[n][i + 1];
      }
      wheel[n][7] = tmp;
   }
}

int reverseTurn(int d) {
   if (d == 1)
      return -1;
   else
      return 1;
}

void turnwheel(int n, int d) {
   int rd = reverseTurn(d);
   // 만약 1번 톱니가 돌면 2,4는 반시계, 3은 1번과 같은 방향으로
   /*
   1번 톱니
   1. 1번의 2와 2번의 6의 같지 않으면 돈다
   1-1. 2번의 2와 3번의 6의 같지 않으면 돈다
   1-2. 3번의 2와 4번의 6의 같지 않으면 돈다
   중간에 만약 같다면? n+1번 톱니는 돌지않는다.

   2번 톱니
   1. 만약 1번톱니와 맞닿은 부분이 같지 않다면 1번은 2번의 반대방향으로 회전
   */
   if (n == 0) {
      if (wheel[n][2] != wheel[n + 1][6]) {
         if (wheel[n + 1][2] != wheel[n + 2][6]) {
            if (wheel[n + 2][2] != wheel[n + 3][6]) {
               orthodromic(n, d);
               orthodromic(n + 1, rd);
               orthodromic(n + 2, d);
               orthodromic(n + 3, rd);
            } else {
               orthodromic(n, d);
               orthodromic(n + 1, rd);
               orthodromic(n + 2, d);
            }
         } else {
            orthodromic(n, d);
            orthodromic(n + 1, rd);
         }
      } else {
         orthodromic(n, d);
      }
   } else if (n == 1) {
      if (wheel[n][6] != wheel[n - 1][2]) {
         orthodromic(n - 1, rd);
      }
      if (wheel[n][2] != wheel[n + 1][6]) {
         if (wheel[n + 1][2] != wheel[n + 2][6]) {
            orthodromic(n, d);
            orthodromic(n + 1, rd);
            orthodromic(n + 2, d);
         } else {
            orthodromic(n, d);
            orthodromic(n + 1, rd);
         }
      } else {
         orthodromic(n, d);
      }
   } else if (n == 2) {
      if (wheel[n][2] != wheel[n + 1][6]) {
         orthodromic(n + 1, rd);
      }
      if (wheel[n][6] != wheel[n - 1][2]) {
         if (wheel[n - 1][6] != wheel[n - 2][2]) {
            orthodromic(n, d);
            orthodromic(n - 1, rd);
            orthodromic(n - 2, d);
         } else {
            orthodromic(n, d);
            orthodromic(n - 1, rd);
         }
      } else {
         orthodromic(n, d);
      }
   } else if (n == 3) {
      if (wheel[n][6] != wheel[n - 1][2]) {
         if (wheel[n - 1][6] != wheel[n - 2][2]) {
            if (wheel[n - 2][6] != wheel[n - 3][2]) {
               orthodromic(n, d);
               orthodromic(n - 1, rd);
               orthodromic(n - 2, d);
               orthodromic(n - 3, rd);
            } else {
               orthodromic(n, d);
               orthodromic(n - 1, rd);
               orthodromic(n - 2, d);
            }
         } else {
            orthodromic(n, d);
            orthodromic(n - 1, rd);
         }
      } else {
         orthodromic(n, d);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   string ns;
   for (int i = 0; i < 4; i++) {
      cin >> ns;
      for (int j = 0; j < ns.length(); j++) {
         wheel[i].push_back(ns[j] - '0');
      }
   }
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      int w, d;
      cin >> w >> d;
      cmd.push_back(make_pair(w - 1, d));  // 인덱스이므로 1 빼줌
   }
   for (int i = 0; i < cmd.size(); i++) {
      int n = cmd[i].first;
      int d = cmd[i].second;
      turnwheel(n, d);
   }
   int ans = 0;
   if (wheel[0][0] == 1) ans += 1;
   if (wheel[1][0] == 1) ans += 2;
   if (wheel[2][0] == 1) ans += 4;
   if (wheel[3][0] == 1) ans += 8;

   cout << ans << endl;

   return 0;
}
