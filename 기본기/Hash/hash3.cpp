#include <iostream>
#include <unordered_map>
using namespace std;

// 가장많이 등장하는 알파벳

unordered_map<char, int> um;

int main() {

    um['A']++;
    um['B']++;
    um['A']++;
    um['A']++;
    um['A']++;
    um['B']++;
    um['A']++;
    um['Q']++;
    um['A']++;
    um['A']++;
    um['T']++;


    int maxx = -21e8;
    char ch;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (um.count(c)) {
            if (maxx < um[c]) {
                maxx = um[c];
                ch = c;
            }
        }
    }

    cout << ch << '\n';

    return 0;
}