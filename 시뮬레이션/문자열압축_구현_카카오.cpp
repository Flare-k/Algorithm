#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    int answer = s.length();

    if (answer == 1) {
        return 1;
    }

    for (int i = 1; i <= s.length() / 2; i++) {
        int cnt = 1;

        string f = s.substr(0, i);
        string obj, ns; // 비교 대상, 숫자 + 문자

        for (int j = i; j < s.length(); j += i) {
            obj = s.substr(j, i);

            if (!(f.compare(obj))) {
                cnt++;
            }
            else {
                if (cnt == 1) {
                    ns += f;
                }
                else {
                    ns = ns + to_string(cnt) + f;
                    cnt = 1;
                }
                f = obj;    // 다음 규칙이 될 문자
            }
            
            if (j + i >= s.length()) {
                if (cnt != 1) {
                    ns = ns + to_string(cnt) + f;
                    break;
                }
                else {
                    ns += s.substr(j);
                    break;
                }
            }
        }

        answer = (answer > ns.length()) ? ns.length() : answer;
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