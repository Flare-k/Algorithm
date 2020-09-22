#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAX = 50 + 1;
int n, m;
char chess[MAX][MAX];
string whiteFirst[8] = {{"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"},
                        {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}};
string blackFirst[8] = {{"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"},
                        {"BWBWBWBW"}, {"WBWBWBWB"}, {"BWBWBWBW"}, {"WBWBWBWB"}};

void init() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
}

int check(int r, int c) {
   int ans = 999999999;
   int whiteCnt = 0;
   int blackCnt = 0;
   for (int i = r; i < r + 8; i++) {
      for (int j = c; j < c + 8; j++) {
         if (whiteFirst[i - r][j - c] != chess[i][j]) {
            whiteCnt++;
         }
         if (blackFirst[i - r][j - c] != chess[i][j]) {
            blackCnt++;
         }
      }
   }
   ans = min(whiteCnt, blackCnt);
   return ans;
}

int main() {
   init();
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      string board;
      cin >> board;
      for (int j = 0; j < m; j++) {
         chess[i][j] = board[j];
      }
   }
   int row = 0;
   int col = 0;
   vector<int> ans;
   int result = 999999999;
   for (int i = 0; i <= n - 8; i++) {
      for (int j = 0; j <= m - 8; j++) {
         result = min(result, check(i, j));
      }
   }
   cout << result << endl;
   return 0;
}