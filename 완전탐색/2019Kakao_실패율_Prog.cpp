#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<double,int> &a, const pair<double, int> &b) {
    //실패율 먼저 비교(내림차순)
    if (a.first > b.first) {
        return true;
    } 
    else if (a.first == b.first) {
        //실패율이 같다면 스테이지 번호를 비교(오름차순)
        if (a.second < b.second) {
            return true;
        } 
        else {
            return false;
        }
    } 
    else {
        return false;
    }
}
 
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int> > failrate;
    
    sort(stages.begin(),stages.end());
    
    //도전중인 사용자 수
    int usernum = int(stages.size());
    int index = 0;
    
    for (int i = 1; i <= N; i++) {
        //i번째 스테이지에 도달한 유저가 없는 경우 실패율은 0
        if(usernum == 0) {
            failrate.push_back(make_pair(0, i));
            continue;
        }

        int failcnt = 0;

        //i번 stage에 도달했지만 클리어하지 못한 사용자수
        while (stages[index] == i) {
            failcnt += 1;
            index++;
        }

        double rate = (double) failcnt/usernum;
        failrate.push_back(make_pair(rate, i)); //각 스테이지에 해당하는 실패율 저장
        
        //i번째까지만 도달한 사용사들의 수를 빼준다.
        usernum -= failcnt;
    }
    
    //문제 조건에 맞게 정렬(실패율 내림차순, 스테이지번호 오름차순)
    sort(failrate.begin(), failrate.end(), comp);
    
    //정답에 실패율이 높은 스테이지의 인덱스를 추가한다.
    for (int i = 0; i < N; i++) {
        answer.push_back(failrate[i].second);
    }
    
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> stages {2, 1, 2, 6, 2, 4, 3, 3};
    
    for (int i = 0; i < solution(n, stages).size(); i++) {
        cout << solution(n, stages)[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
