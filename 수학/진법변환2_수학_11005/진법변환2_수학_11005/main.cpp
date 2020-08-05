#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;
/*
 10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.
 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
 A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

 입력
 첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

 출력
 첫째 줄에 10진법 수 N을 B진법으로 출력한다.
 
 예제 입력 1
 60466175 36
 예제 출력 1
 ZZZZZ
 0 1 2 ... 9 A B C D E F
 
 10진법 -> B진법 변환..
 A:10, B:11 -> 'A' - 55의 경우.
 
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num, conv;
    cin >> num >> conv;
    string sum = "";
    
    
    // 10진법 이하인 경우..
    if (conv <= 10){
        while (num) {
            sum += to_string(num%conv);
            num /= conv;
        }
    }
    // 11진법 이상인 경우..
    if (conv > 10){
        while (num) {
            if(num%conv >= 10){
                sum += (char)('A' + num%conv - 10);
            }
            else{
                sum += to_string(num%conv);
            }
            num /= conv;
        }
    }
    
    string ans = "";
    for (int i=sum.size()-1; i>=0; i--){
        ans += sum[i];
    }
    //아스키 A = 65
    cout << ans <<endl;
    
    return 0;
}
// 10 = 1010

