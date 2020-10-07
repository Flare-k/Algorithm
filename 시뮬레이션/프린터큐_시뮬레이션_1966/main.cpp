#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
/*
1. 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이
문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를
한다.
*/
int n;  // 전체 test case 개수
int page, w;
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> n;

   while (n--) {
      int answer = 0;
      priority_queue<int> pq;
      queue<pair<int, int> > q;
      cin >> page >> w;
      for (int i = 0; i < page; i++) {
         int a;
         cin >> a;
         q.push(make_pair(i, a));  // a=문서의 중요도, i=문서의 순서
         pq.push(a);
      }
      //만약 찾고자 하는 w가 같다면 몇번째로 출력된건지 출력
      // 그렇지 않다면 pop해서 뒤로 push
      // 현재 중요도 보다 큰 중요도가 있다면 그거먼저 출력하게 하기.
      // 우선순위 큐 이용할 것!
      while (!q.empty()) {
         int idx = q.front().first;
         int weight = q.front().second;
         q.pop();
         if (weight == pq.top()) {
            answer += 1;
            pq.pop();
            if (idx == w) break;
         } else {
            q.push(make_pair(idx, weight));
         }
      }
      cout << answer << endl;
   }

   return 0;
}