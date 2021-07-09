#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string head;
    string number;
    string tail;
    int idx;    // number를 정수화
};

// 소문자로 변경
string transLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

bool cmp(Node a, Node b) {
    string strA = transLower(a.head);
    string strB = transLower(b.head);

    if (strA < strB) return true;
    else if (strA == strB) return a.idx < b.idx;
    return false;
}

void split(string file, string& head, string& number, string& tail) {
    int idx = 0;
    int cnt = 0;
    // head
    for (int i = 0; i < file.length(); i++) {
        if (file[i] >= '0' && file[i] <= '9') {
            head = file.substr(idx, cnt);
            idx += cnt;
            break;
        }
        cnt++;
    }

    // number
    cnt = 0;
    for (int i = idx; i < file.length(); i++) {
        if (file[i] >= '0' && file[i] <= '9') {
            cnt++;
            if (cnt == 5) break;
        }
        else {
            number = file.substr(idx, cnt);
            idx += cnt;
            break;
        }
    }

    if (number.empty()) {
        number = file.substr(idx, cnt);
        idx += cnt;
    }
    
    // tail
    tail = file.substr(idx);
}

vector<string> solution(vector<string> files) {
    vector<Node> arr;

    for (string file : files) {
        string head, number, tail;
        split(file, head, number, tail);
        arr.push_back({head, number, tail, stoi(number)});
    }
    
    stable_sort(arr.begin(), arr.end(), cmp);       // c++ 에서의 포인트

    vector<string> answer;

    for (int i = 0; i < arr.size(); i++) {
        Node now = arr[i];
        answer.push_back(now.head + now.number + now.tail);
    }

    return answer;
}

int main() {
    vector<string> ans = solution({"F-15", "img000032345", "img1.png","img2","IMG02"});

    for (string str : ans) {
        cout << str << '\n';
    }

    return 0;
}