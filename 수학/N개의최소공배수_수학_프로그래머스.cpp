#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        answer  = lcm(answer, arr[i]);
    }
    
    return answer;
}

int main() {
    int ans = solution({1, 2});

    cout << ans;
    return 0;
}