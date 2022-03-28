#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void run(string S, string T) {
    if (S == T) {
        cout << 1 << '\n';
        exit(0);
    }

    if (S.length() >= T.length()) return;
    
    string tmp;
    
    if (T.back() == 'A') { 
        tmp = T.substr(0, T.length() - 1);
        run(S, tmp);
    }
    
    if (T.front() == 'B') {
        tmp = T.substr(1);
        reverse(tmp.begin(), tmp.end());
        run(S, tmp);
    }
    
}


int main() {
    string S, T;
    cin >> S >> T;

    run(S, T);
    
    cout << 0 << '\n';

    return 0;
}