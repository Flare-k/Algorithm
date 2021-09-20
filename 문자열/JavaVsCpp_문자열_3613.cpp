#include <iostream>
#include <vector>
#include <string>
using namespace std;

string var;
vector<string> cpp;
vector<string> java;

string splitCpp() {
    int left = 0;
    int right = 0;

    while (1) {
        right = var.find('_', left);
        if (right == -1) {
            cpp.push_back(var.substr(left));
            break;
        }

        cpp.push_back(var.substr(left, right - left));
        left = right + 1;
    }

    string answer = cpp[0];

    for (int i = 1; i < cpp.size(); i++) {
        cpp[i][0] = toupper(cpp[i][0]);
        answer += cpp[i];
    }

    return answer;
}

string splitJava() {
    string tmp = "";
    for (char ch : var) {
        if (isupper(ch)) {
            java.push_back(tmp);
            tmp = "";
        }

        tmp += ch;
    }
    java.push_back(tmp);

    string answer = java[0];

    for (int i = 1; i < java.size(); i++) {
        java[i][0] = tolower(java[i][0]);
        answer = answer + "_" + java[i];
    }

    return answer;
}

bool checkJavaOrCpp() {
    for (char ch : var) {
        if (ch == '_') return true;
    }
    return false;
}

bool checkErrorCase() {
    bool underBar = false, capital = false;

    // 첫 글자가 대문자인 경우
    if (var[0] < 97) return true;

    // 알파벳, _를 제외한 문자가 나올 경우
    for (char ch : var) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_') continue;
        else return true;
    }

    // 첫글자 or 마지막 글자가 언더바인 경우
    if (var.front() == '_' || var.back() == '_') return true;

    // 언더바가 나오는데 대문자도 나오는 경우   
    for (char ch : var) {
        if (ch >= 'A' && ch <= 'Z') capital = true;
        if (ch == '_') underBar = true;
    }

    if (underBar == true && capital == true) return true;

    // 언더바가 연속으로 두번 나올 경우
    for (int i = 0; i < var.length() - 1; i++) {
        if (var[i] == '_' && var[i + 1] == '_') return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> var;

    if (checkErrorCase()) {
        cout << "Error!";
    }
    else {
        if (checkJavaOrCpp()) { // cpp인 경우
            cout << splitCpp();

        }
        else {  // java인 경우
            cout << splitJava();
        }
    }

    return 0;
}