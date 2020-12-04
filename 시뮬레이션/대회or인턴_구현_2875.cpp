#include <algorithm>
#include <iostream>
using namespace std;
/*
 백준대학교 여자 2명, 남자 1명 대회 나감
 N명의 여자, M명의 남자 선발중
 대회에 참여하려는 학생들 중 K명은 반드시 인턴쉽 프로그램에 참여해야 한다.
 #인턴쉽에 참여하는 학생은 대회에 참여하지 못한다.#
 여러분은 여학생의 수 N, 남학생의 수 M, 인턴쉽에 참여해야하는 인원 K가 주어질 때
 만들 수 있는 최대의 팀 수를 구하면 된다.

 1. K가 없다면 여자의 1/2배 또는 남자의 수 중 최소 값이 최대 팀 수
 2. K가 있다면 K명은 없다고 가정해야 함. -> N+M-K에서 3명씩 팀을 짜야 한다.
 3. 1, 2에서 경우에 따라서 최소 값을 최대 팀 수로 채택.
*/
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n, m, k;
   cin >> n >> m >> k;
   cout << min(min(n / 2, m), (n + m - k) / 3) << endl;
   return 0;
}