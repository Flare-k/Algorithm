#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Ball {
    int r;  // 행
    int c;  // 열
    int m;  // 질량
    int s;  // 속력
    int d;  // 방향
};

vector<Ball> arr[55][55];
vector<Ball> balls;

int checkEvenOdd(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K; // N 행렬의 크기, M 입력 개수, K 반복횟수

    int r, c, m, s, d;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        balls.push_back({r, c, m, s, d});
    }

    while (K--) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j].clear();
            }
        }

        for (int i = 0; i < balls.size(); i++) {
            // 1단계
            int nr = balls[i].r + dx[balls[i].d] * (balls[i].s % N);
            int nc = balls[i].c + dy[balls[i].d] * (balls[i].s % N);

            while (nr > N) nr -= N;
            while (nc > N) nc -= N;
            while (nr < 1) nr += N;
            while (nc < 1) nc += N;

            // 같은 칸에 있는 경우 하나로 모으기
            balls[i].r = nr;
            balls[i].c = nc;

            arr[nr][nc].push_back(balls[i]);
            
        }

        vector<Ball> tmp;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j].size() == 0) continue;
                if (arr[i][j].size() == 1) {
                    tmp.push_back(arr[i][j][0]);
                    continue;
                }

                int mSum = 0, sSum = 0;

                for (int k = 0; k < arr[i][j].size(); k++) {
                    mSum += arr[i][j][k].m;
                    sSum += arr[i][j][k].s;
                }

                int m = mSum / 5;
                if (m == 0) continue;

                int s = sSum / arr[i][j].size();
                int d = checkEvenOdd(i, j);

                for (int k = 0; k < 4; k++) {  
                    tmp.push_back({i, j, m, s, d});
                    d += 2;
                }
            }
        }

        balls = tmp;
    }


    int sum = 0;
    for (int i = 0; i < balls.size(); i++) {
        sum += balls[i].m;
    }

    cout << sum;

    return 0;
}


int checkEvenOdd(int x, int y) {
   int even = 0;
   int odd = 0;

   for (int i = 0; i < balls.size(); i++) {
      if (balls[i].r == x && balls[i].c == y) {
         if (balls[i].d % 2 == 0)
            even++;
         else
            odd++;
      }
   }

   if (even != 0 && odd == 0)
      return 0;
   else if (even == 0 && odd != 0)
      return 0;
   else if (even != 0 && odd != 0)
      return 1;

   return 0;
}