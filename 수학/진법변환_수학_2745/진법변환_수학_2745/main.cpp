#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string num;
    int conv;
    cin >> num >> conv;
    
    string test="";
    for (int i=num.size()-1; i>=0; i--)
        test += num[i];
    
    int sum = 0;
    
    for (int i = 0; i < test.size(); i++){
        int temp = 0;
        if(test[i] - 'A' >= 0){
            temp = test[i] - 'A' + 10;
            sum += temp * pow(conv, i);
        }
        else if('0' <= test[i] && test[i] <= '9'){
            temp = test[i] - '0';
            sum += temp * pow(conv, i);
        }
    }
    cout << sum << endl;
    
    return 0;
}
/*
 만약
 16진법의 F를 10진법으로 바꾼다면... 15로 나와야 한다. 이걸 어떻게 표현하면 좋을까...
 A = 65
 B진법 -> 10진법
 예를들어 2진법이라 하자... 1010 -> 10 각 자리수대로 2^n * 자리의 계수
 만약 해당 값을  - 'A' 했을 때 양수인경우(알파벳) 음수읜 경우 (숫자)
 */
/*
 다른 사람의 코드..
 #include <iostream>
 #include <string>

 using namespace std;

 int main() {
     int ans = 0;
     string s;
     int b;
     
     cin >> s >> b;
     
     for (int i=0; i<s.size(); i++)
     {
         if ('0' <= s[i] && s[i] <= '9')
             ans = ans * b + (s[i] - '0');
         else
             ans = ans * b + (s[i] - 'A' + 10);
     }
     
     cout << ans << '\n';
 }
 */
