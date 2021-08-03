#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t;

bool checkSym(string num) {
    int s = 0, e = num.length() - 1;

    while (s <= e) {
        if (num[s] == num[e]) {
            s++;
            e--;
            continue;
        }
        else return false;
    }

    return true;
}

int main() {

    cin >> t;

    while (t--) {
        string a, b;
        cin >> a;
        
        b = a;
        reverse(b.begin(), b.end());

        string sum = to_string(stoi(a) + stoi(b));
        
        if (checkSym(sum)) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}