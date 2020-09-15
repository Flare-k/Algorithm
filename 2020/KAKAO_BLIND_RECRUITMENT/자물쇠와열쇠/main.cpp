// 인덱스 설정 및 구현 어렵다ㅠㅠ
#include <iostream>
#include <vector>
using namespace std;

int keysize, locksize, boardsize;
// key를 시계방향으로 90도씩 회전시키는 경우
void rotateKey(vector<vector<int> > &key) {
   vector<vector<int> > tmp(keysize, vector<int>(keysize));

   for (int j = keysize - 1; j >= 0; j--) {
      for (int i = 0; i < keysize; i++) {
         tmp[i][j] = key[keysize - j - 1][i];
      }
   }
   // 이전의 행이 다음의 (keysize-1)열이 된다.
   /*
    0도의 0행 -> 90도의 2열
    0도의 1행 -> 90도의 1열
    0도의 2행 -> 90도의 0열
   */
   key = tmp;  // 90도 회전 후 key값 갱신
}

bool putKey(int x, int y, vector<vector<int> > key,
            vector<vector<int> > board) {
   //(x, y)를 시작점으로 열쇠를 자물쇠에 맞춰본다.

   // key를 더한다
   for (int i = x; i < x + keysize; i++) {
      for (int j = y; j < y + keysize; j++) {
         board[i][j] += key[i - x][j - y];
      }
   }
   //좌표를 움직이면서 board의 범위내에서 다 끼워맞춰본다.

   //좌물쇠 부분 확인
   for (int i = keysize - 1; i <= boardsize - keysize; i++) {
      for (int j = keysize - 1; j <= boardsize - keysize; j++) {
         if (board[i][j] == 1) continue;

         // 1이 아니라면 바로 false를 리턴
         // 1이 넘어가면 그것또한 딱맞는 키가 아니므로 1이 아니면 false이다.
         return false;
      }
   }
   // 만약 ==1이 모두 continue로 빠졌다면 lock 전부가 1이 된것이므로 해당 키가
   // 맞는 것이다.
   return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
   bool answer = false;

   keysize = key.size();
   locksize = lock.size();

   boardsize = locksize + (keysize - 1) * 2;
   vector<vector<int> > board(boardsize, vector<int>(boardsize, 0));

   // board에 lock을 미리 더해놓는다. (lock은 고정되어 있고 key를 움직일 것
   // 이므로)
   for (int i = keysize - 1; i <= boardsize - keysize; i++) {
      for (int j = keysize - 1; j <= boardsize - keysize; j++) {
         board[i][j] = lock[i - keysize + 1][j - keysize + 1];
      }
   }

   //회전 방향 네번
   for (int r = 0; r < 4; r++) {
      for (int i = 0; i <= boardsize - keysize; i++) {
         for (int j = 0; j <= boardsize - keysize; j++) {
            // i,j 를 key의 시작칸으로 자물쇠 홈에 맞춰본다.
            if (putKey(i, j, key, board)) {
               answer = true;
               return answer;
            }
         }
      }

      // key 시계방향으로 90도 회전
      rotateKey(key);
   }

   return answer;
}

int main() {
   vector<vector<int> > key(3, vector<int>(3, 0));
   vector<vector<int> > lock(3, vector<int>(3, 0));

   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         int num;
         cin >> num;
         key[i][j] = num;
      }
   }
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         int num;
         cin >> num;
         lock[i][j] = num;
      }
   }
   cout << solution(key, lock) << endl;
   return 0;
}
/*
0 0 0
1 0 0
0 1 1
1 1 1
1 1 0
1 0 1
*/