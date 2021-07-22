#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#define ll long long;
using namespace std;

const long long M = 1234567891;

unordered_map<char, int> map;

void init() {
    for (int i = 0; i < 26; i++) {
        char ch = char('a' + i);
        map[ch] = i + 1;
    }
}

long long diyPow(int n, int roof) {
    long long result = 1;
    while (roof--) {
        result *= n;
        result %= M;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();
    
    int n;
    string str;
    cin >> n >> str;

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += map[str[i]] * diyPow(31, i) % M;
    }

    cout << sum % M;

    return 0;
}