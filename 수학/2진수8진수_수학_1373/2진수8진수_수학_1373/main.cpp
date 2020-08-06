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
    cin >> num;
    
    string test="";
    for (int i=num.size()-1; i>=0; i--)
        test += num[i];
    // 1의 자리부터 계산해주기 위해 순서를 바꿔준다.
    string conn = "";   // 8진수로 바꿨을 때 이 변수에 저장한다.

    for (int i = 0; i < test.size(); i+=3){     //2진수 -> 8진수로 변환시에 세자리씩 나눠서 처리해준다.
        int idx = 0, sum = 0;
        
        for(int j = i; j < i+3; j++){
            int temp = 0;
            if('0' <= test[j] && test[j] <= '9'){
                temp = test[j] - '0';
                sum += temp * pow(2, idx);
                idx++;
            }
        }
        conn += to_string(sum);     // 세자리씩 나눠서 합을 처리하고 conn 변수에 더해준다.
    }
    string ans = "";
    for (int i=conn.size()-1; i>=0; i--)
        ans += conn[i];
    cout << ans << endl;
    
    return 0;
}
