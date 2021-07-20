#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string run(int num) {
    string s = "";

    while (num != 0) {
        s += to_string(num % 2);
        num /= 2;
    }

    s.pop_back();
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') s[i] = '4';
        else s[i] = '7';
    }

    return s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long num;
    cin >> num;
    
    cout << run(num + 1);

    return 0;
}