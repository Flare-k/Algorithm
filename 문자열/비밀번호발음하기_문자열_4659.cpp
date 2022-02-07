#include <iostream>
#include <string>
using namespace std;


bool checkMo(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return false;
    return true;
}

bool checkJaMo(string s) {
    for (int i = 0; i <= s.length() - 3; i++) {
        string tmp = s.substr(i, 3);

        if (checkMo(tmp[0]) == true && checkMo(tmp[1]) == true && checkMo(tmp[2]) == true) return false;
        else if (checkMo(tmp[0]) == false && checkMo(tmp[1]) == false && checkMo(tmp[2]) == false) return false;
    }

    return true;
}

bool checkConsecutive(string s) {
    for (int i = 0; i <= s.length() - 2; i++) {
        string tmp = s.substr(i, 2);

        if (tmp[0] == tmp[1]) {
            if (tmp[0] == 'e' || tmp[0] == 'o') continue;
            else return false;
        }
    }

    return true;
}

bool checkPassword(string pwd) {
    bool mo = false;

    // 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
    for (char ch : pwd) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            mo = true;
            break;
        }
    }

    if (!mo) return false;


    // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    if (pwd.length() >= 3) {
        if (!checkJaMo(pwd)) return false;
    }

    // 3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다
    if (pwd.length() >= 2) {
        if (!checkConsecutive(pwd)) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string pwd;

    while (1) {
        cin >> pwd;

        if (pwd == "end") break;

        if (checkPassword(pwd)) cout << '<' << pwd << "> is acceptable.\n";
        else cout << '<' << pwd << "> is not acceptable.\n";
    }

    return 0;
}