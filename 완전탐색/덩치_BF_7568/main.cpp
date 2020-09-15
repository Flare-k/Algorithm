#include <iostream>
#include <utility>
#include <vector>
using namespace std;
/*
<몸무게, 키>

몸무게와 키 모두 타인보다 클 경우 덩치가 크다고 정의한다.
자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 등수는 k+1이 된다.
이렇게 되면 같은 덩치 등수를 갖는 사람도 여러 명 존재하게 될 것이다.
*/

vector<int> compare(vector<pair<int, int> > person) {
   vector<int> answer;
   for (int i = 0; i < person.size(); i++) {
      int rank = 1;  // 덩치 등수 표현
      for (int j = 0; j < person.size(); j++) {
         if (person[i].first < person[j].first &&
             person[i].second < person[j].second) {
            rank++;
         }
      }
      answer.push_back(rank);
   }

   return answer;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin >> n;
   vector<pair<int, int> > person;
   for (int i = 0; i < n; i++) {
      int kg, cm;
      cin >> kg >> cm;
      person.push_back(make_pair(kg, cm));
   }
   for(int i=0; i<compare(person).size(); i++){
       cout << compare(person)[i] << " ";
   }

   return 0;
}