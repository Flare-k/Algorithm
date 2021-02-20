#include <iostream>
#include <string>
using namespace std;

int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};  // L R U D
char moveType[4] = {'L', 'R', 'U', 'D'};

int main() {
   cin >> n;
   cin.ignore();
   string plans;
   getline(cin, plans);

   int x = 1, y = 1;

   for (int i = 0; i < plans.size(); i++) {
      char plan = plans[i];
      int nx = -1, ny = -1;
      for (int j = 0; j < 4; j++) {
         if (plan == moveType[j]) {
            nx = x + dx[j];
            ny = y + dy[j];
         }
      }
      if (nx < 1 || n < nx || ny < 1 || n < ny) continue;
      x = nx;
      y = ny;
   }
   cout << x << ' ' << y << endl;
   return 0;
}
/*
5
R R R U D D
*/