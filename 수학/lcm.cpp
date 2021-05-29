#include <iostream>
using namespace std;
/*
 최소공배수(lcm)를 구하는 알고리즘
 */

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(){
    int n;
    int a, b;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    
    return 0;
}
