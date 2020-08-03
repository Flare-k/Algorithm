#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

// 최대 공약수 GCD
long long gcd(long long a, long long b){
    // ex 24, 18
    if(b == 0)
        return a;
    else{
        return gcd(b, a%b);
    }
}
// 최소 공배수 LCM
long long lcm(long long a, long long b){
    return (a*b)/gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
    long long a, b;
    cin >> a >> b;
    string ans = "";
    for (int i=0; i<gcd(a, b); i++){
        ans += "1";
    }
    cout << ans << endl;
    
    return 0;
}
