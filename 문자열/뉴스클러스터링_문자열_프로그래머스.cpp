#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

void transLow(string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
    }
}

bool stringCheck(string tmp) {
    if (tmp.front() >= 'a' && tmp.front() <= 'z') {
        if (tmp.back() >= 'a' && tmp.back() <= 'z') return true;
    }
    return false;
}

unordered_map<string, int> leftMap;
unordered_map<string, int> rightMap;
set<string> strList;

int solution(string str1, string str2) {
    int answer = 0;
    transLow(str1);
    transLow(str2);

    for (int i = 0; i < str1.length() - 1; i++) {
        string tmp = str1.substr(i, 2);
        if (stringCheck(tmp)) {
            strList.insert(tmp);
            leftMap[tmp]++;
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        string tmp = str2.substr(i, 2);
        if (stringCheck(tmp)) {
            strList.insert(tmp);
            rightMap[tmp]++;
        }
    }

    double k = 0, h = 0;
    
    // 교집합
    for (string str : strList) {
        if (leftMap.count(str) && rightMap.count(str)) {
            k += min(leftMap[str], rightMap[str]);
        }
    }

    // 합집합
    for (string str : strList) {
        if (leftMap.count(str) || rightMap.count(str)) {
            h += max(leftMap[str], rightMap[str]);
        }
    }
    
    if (k == 0 && h == 0) {
        k = 1;
        h = 1;
    }

    answer = (k / h) * 65536;

    return answer;
}


int main() {
    cout << solution("FRANCE", "french") << '\n';
    return 0;
}