#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
   int answer = s.length();
   if (answer == 1) return 1;  // 만약 문자열의 길이가 1이었다면 1 리턴

   for (int i = 1; i <= s.length() / 2; i++) {
      // 한 글자부터 비교하기 위해 i=1부터 시작.
      int cnt = 1;
      string f = s.substr(0, i);  // 0~i 까지의 문자나누기
      string cmp, cp;  // cmp: 비교대상문자열, cp: 숫자+문자열

      for (int j = i; j < s.length(); j += i) {
         cmp = s.substr(j, i);  // 만약 i=2여서 두글자씩 탐색한다고 하면
                                // 인덱스2부터 두글자, 인덱스 4부터 2글자..

         if (!(f.compare(cmp))) {  //두 문자(f & cmp)가 같으면 0을 리턴
            cnt++;
         } else {
            if (cnt == 1) {
               cp += f;
               f = cmp;
            } else {
               cp = cp + to_string(cnt) +
                    f;  //만약 같지 않으면 지금까지의 f와 count를 합쳐준다.
               f = cmp;  // f는 새로운 값인 cmp로 갱신
               cnt = 1;
            }
         }
         if (j + i >= s.length()) {  //마지막에 substr기준을 초과한 경우
            if (cnt != 1) {
               cp = cp + to_string(cnt) + f;
               break;
            } else {
               cp = cp + s.substr(j);
               break;
            }
         }
      }
      answer = (answer > cp.length()) ? cp.length() : answer;
   }

   return answer;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   string str;
   cin >> str;
   cout << solution(str) << '\n';

   return 0;
}

// abcd ab ef