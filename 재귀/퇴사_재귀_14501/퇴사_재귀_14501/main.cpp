/*
 go(day, sum)
 - day일이 되었다. day일에 있는 상담을 할지 말지 결정해야 한다.
    (day일에 있는 상담을 이미 할지 말지 결정했다. 와는 완전 다른 내용이다)
 - 지금까지 얻은 수익은 sum이다.
 
 day는 index와 같은 의미이다.
 부분집합의 합 문제에서는 index번째에 있는 수를 부분집합에 포함하냐 안하냐
 로또 문제는 index번째의 수를 포함한다 안한다
 암호 문제는 index번째의 알파벳을 암호에 포함한다 안한다.
 
 day일에 있는 상담을 할지말지..
 (첫날은 0일, 마지막 날은 n-1일로 설정할 것.) // 퇴사: n일
 1. 불가능한 경우: day > n+1
 2. 정답을 찾은 경우: day == n+1
 3. 다음경우호출: 상담하는 경우   : go(day+T[day], sum+P[day])
              상담하지 않는 경우:go(day+1, sum)
 
 */
#include <iostream>
using namespace std;
int n;
int t[15];
int p[15];
int ans=0;

void go(int day, int sum){
    if(day > n) return;
    if(day == n){
        if(ans < sum)
            ans = sum;
        return;
    }
    go(day+t[day], sum+p[day]);
    go(day+1, sum);
}

int main(){
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t[i]>>p[i];
    }
    go(0,0);
    cout<<ans<<'\n';
    return 0;
}
