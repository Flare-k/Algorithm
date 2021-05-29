#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

// 최대 공약수 GCD
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long num;
    cin >> num;
    
    while (num--) {
        vector<long long> temp;
        int turns;
        cin >> turns;

        for (int i = 0; i < turns; i++) {
            long long tempNum;
            cin >> tempNum;
            temp.push_back(tempNum);
        }

        long long sum = 0;  // long long 중요

        for (int i = 0; i < temp.size()-1; i++) {
            for (int j = i+1; j < temp.size(); j++) {
                sum += gcd(temp[i], temp[j]);
            }
        }

        cout << sum << endl;
        
    }
    
    return 0;
}