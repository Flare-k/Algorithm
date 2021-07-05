#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> um;

int main() {

    um["BTS"] = 1;
    um["KFC"] = 1;
    um["A"] = 1;
    um["B"] = 1;
    um["C"] = 1;

    int n;
    cin >> n;

    string answer = "";
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (um.count(str)) answer += "O";
        else answer += "X";

    }

    cout << answer;

    return 0;
}
