#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 이분탐색
// 길이로 먼저 정렬하고 길이가 같다면 사전순으로 정렬
bool comp(string a, string b) {
   if (a.length() < b.length())
      return true;
   else if (a.length() == b.length())
      if (a < b) return true;
   return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
   vector<int> answer;

   // rwords 벡터에 단어를 뒤집어서 저장
   vector<string> rwords = words;
   int size = rwords.size();
   for (int i = 0; i < size; i++) reverse(rwords[i].begin(), rwords[i].end());

   // comp 기준 정렬
   sort(words.begin(), words.end(), comp);
   sort(rwords.begin(), rwords.end(), comp);

   int len, lo, hi;
   int idx;
   for (string query : queries) {
      len = query.length();

      if (query[0] == '?') {
         //?가 접두사에 있는 경우
         reverse(query.begin(), query.end());  //키워드도 뒤집어준다.
         idx = query.find_first_of('?');  // 물음표가 나오는 첫 인덱스

         for (int i = idx; i < len; i++) query[i] = 'a';
         lo = lower_bound(rwords.begin(), rwords.end(), query, comp) -
              rwords.begin();

         for (int i = idx; i < len; i++) query[i] = 'z';
         hi = upper_bound(rwords.begin(), rwords.end(), query, comp) -
              rwords.begin();
      } else {
         //?가 접미사에 있는 경우
         idx = query.find_first_of('?');

         for (int i = idx; i < len; i++) query[i] = 'a';
         lo = lower_bound(words.begin(), words.end(), query, comp) -
              words.begin();

         for (int i = idx; i < len; i++) query[i] = 'z';
         hi = upper_bound(words.begin(), words.end(), query, comp) -
              words.begin();
      }

      answer.push_back(hi - lo);
   }

   return answer;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   vector<string> words;
   vector<string> queries;
   for (int i = 0; i < 6; i++) {
      string a;
      cin >> a;
      words.push_back(a);
   }

   for (int i = 0; i < 5; i++) {
      string a;
      cin >> a;
      queries.push_back(a);
   }
   for (int i = 0; i < 5; i++) {
      cout << solution(words, queries)[i] << " ";
   }
   cout << endl;
   return 0;
}

/*
frodo front frost frozen frame kakao
fro?? ????o fr??? fro??? pro?
*/