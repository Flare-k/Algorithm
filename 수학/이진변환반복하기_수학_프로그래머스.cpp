#include <iostream>
#include <string>
#include <vector>

using namespace std;

int removeCount = 0;

string removeZero(string tmp) {
    string ans = "";

    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == '1') ans += tmp[i];
        else removeCount++;
    }

    return ans;
}

string convertBinary(int len) {
    string tmp = "";
    string ans = "";

    while (len != 0) {
        tmp += to_string(len % 2);
        len /= 2;
    }

    for (int i = tmp.length() - 1; i >= 0; i--) {
        ans += tmp[i];
    }

    return ans;
}

vector<int> solution(string s) {
    vector<int> answer;

    int totalCnt = 0;
    while (s != "1") {
        string tmp = removeZero(s);
        
        int len = tmp.length();
        s = convertBinary(len);
        totalCnt++;
    }

    answer.push_back(totalCnt);
    answer.push_back(removeCount);

    return answer;
}

int main() {

    vector<int> sol = solution("110010101001");

    for (int num : sol) {
        cout << num << ' ';
    }

    return 0;
}