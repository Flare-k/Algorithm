#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
회원관리 시스템을 새로 구축 하였습니다.
새로운 시스템의 회원 아이디 규칙은 다음과 같습니다.

1. 모두 대문자
2. 첫 글자 대문자, 나머지 소문자

[변경 규칙]
첫 글자 대문자이고, 나머지 소문자 --> 변경하지 않습니다.
소문자로만 이루어진 회원들 --> 첫 글자 대문자, 나머지 소문자로 아이디로 변경합니다. 
그 밖에 대소문자가 섞여있는 회원들 --> 모두 대문자로 아이디를 변경합니다.
*/

int checkRule(string member) {
    int check = 0;
    int len = member.length();

    for (int i = 0; i < len; i++) {
        if (islower(member[i])) check++;
    }

    if (check == len - 1) {
        return 1;   // 첫글자가 대문자이고 모두 소문자
    }
    else if (check == len) {
        return 2;   // 소문자로만 
    }
    else {
        return 3;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> members(n);

    for (int i = 0; i < n; i++) {
        cin >> members[i];
    }

    int idx = 0;
    for (auto member : members) {
        // 첫글자가 소문자일 때 대문자로 바꾸나 모두 소문자일 때 대문자로 바꾸나 똑같음
        int check = checkRule(member);

        if (check == 1) {
            members[idx] = member;
        }
        else if (check == 2) {
            member[0] = toupper(member[0]);
            members[idx] = member;
        }
        else {
            for (int i = 0; i < member.length(); i++) {
                member[i] = toupper(member[i]);
            }
            members[idx] = member;
        }

        idx++;
    }

    sort(members.begin(), members.end());

    for (auto member : members) {
        cout << member << '\n';
    }

    return 0;
}