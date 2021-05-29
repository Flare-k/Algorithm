#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
 /*
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> tree;
    for (int i = 0; i < skill.length(); i++)
        tree[skill[i]] = i + 1;
    for (auto skt : skill_trees) {
        int count = 1;
        bool check = true;
        for (int i = 0; i < skt.length(); i++) {
            if (tree[skt[i]] > count) {
                check = false;
                break;
            }
            else if (tree[skt[i]] == count)
                count++;
        }
        if (check)
            answer++;
    }
    return answer;
}*/
int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        vector<char> compare;
        string s = skill_trees[i];

        for (int k = 0; k < s.size(); k++) {    //주어진 문장의 길이
            for (int j = 0; j < skill.size(); j++) {    //입력한 문자의 길이
                if (s[k] == skill[j]) { //k고정 j가 여러번 반복
                    char tmp = skill[j];
                    compare.push_back(tmp); //만약 CBD의 순서가아니면 다른순서로 저장이 될 거임
                }
            }
        }

        bool check = true; //string vector의 문장 하나마다 체크해줌

        for (int c = 0; c < compare.size(); c++) {
            if (skill[c] != compare[c]) check = false;
        }
        
        if (check)answer++;
    }

    return answer;
}

int main(){
    string skill;
    
    vector<string> skill_trees{"BACDE", "CBADF", "AECB", "BDA"};
    
    skill = "CBD";
    
    cout<<solution(skill, skill_trees)<<'\n';
    
    return 0;
}
