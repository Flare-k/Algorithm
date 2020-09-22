#include <iostream>
#include <string>
using namespace std;

/*
"N번째로 작은 666을 가진 숫자"
1666 2666 3666 4666 5666 6660 6661 ...
수가 작은 것부터 나열하는 건데 천의 자리를 늘려서 7666을 만들면 6660보다 크니까
순서대로가 아니다.
*/
int Findseries(int N) {
   int i = 666;
   int series = 0;
   string target;
   while (1) {
      target = to_string(i);
      for (int j = 0; j < target.length() - 2; j++)
         if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6') {
            series++;
            if (series == N) return i;
            break;
         }
      i++;
   }
}
int main() {
   int N;
   cin >> N;
   cout << Findseries(N);
}