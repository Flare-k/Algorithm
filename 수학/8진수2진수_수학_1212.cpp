#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <algorithm>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<long long> ans;
    string num;
    cin >> num;

    if (num == "0" && num.length()==1){
        cout << 0 << endl;
        return 0;
    }
        
    for (int i = num.length() - 1; i >= 0; i--){
        int temp = num[i] - '0';
        int cnt = 0;

        while(temp){
            ans.push(temp%2);
            temp /= 2;
            cnt++;
        }

        if (cnt != 3 && i != 0){
            for(int j = 0; j < 3 - cnt; j++)
                ans.push(0);
        }   /* 세자리씩 나눠서 2진수로 바꾸는데, 만약 세자리 연산이 끝나기 전에 반복이 끝난다면
             남은 자리만큼 0을 채워줘야한다. 단, 맨 앞자리 수는 빈자리에 0을 채울 필요가 없다.
             */

    }
    
    while (!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    
    cout << endl;
    
    return 0;
}
