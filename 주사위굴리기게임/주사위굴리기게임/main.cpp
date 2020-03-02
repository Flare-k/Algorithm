#include <iostream>
#include<ctime>
using namespace std;
//주사위 굴리기 게임
int main() {
 int a,b=0;
 srand((unsigned int)time(NULL));
 for (int i = 0; i < 10; i++) {
  
  a = rand() % 6 + 1;
  cout <<a<< endl;
  b = a + b;
 }
 cout << b << endl;
 system("pause");
 return 0;
}
