#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node {
    string id;
    string name;
    bool status;    // in = 1, out = 0 -> 따로 사용은 안 했지만 조건이 더 디테일했으면 사용했을법하다.
};

void split(string r, string& status, string& id, string& name) {
    vector<string> tmp;

    int left = 0, right = 0;
    while (1) {
        right = r.find(' ', left);

        if (right == -1) {
            tmp.push_back(r.substr(left));
            break;
        }
        else {
            tmp.push_back(r.substr(left, right - left));
            left = right + 1;
        }
    }

    if (tmp[0] == "Enter" || tmp[0] == "Change"){
        status = tmp[0];
        id = tmp[1];
        name = tmp[2];
    }
    else {  // Leave는 명령어가 두개이므로
        status = tmp[0];
        id = tmp[1];
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, Node> node;

    for (string r : record) {
        string status, id, name;
        split(r, status, id, name);

        if (status == "Enter") {
            node[id] = {id, name, true};
        }
        else if (status == "Leave") {
            node[id] = {id, node[id].name, false};
        }
        else {  // Change
            node[id] = {id, name, node[id].status};
        }
    }

    for (string r : record) {
        string status, id, name;
        split(r, status, id, name);

        if (status == "Enter") {
            answer.push_back(node[id].name + "님이 들어왔습니다.");
        }
        else if (status == "Leave") {
            answer.push_back(node[id].name + "님이 나갔습니다.");
        }
    }

    return answer;
}

int main() {
    
    vector<string> ans = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
    
    for (string str : ans) {
        cout << str << '\n';
    }

    return 0;
}