#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));        //인덱스와 값들을 집어넣기
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        int idx = q.front().first;
        int p = q.front().second;
        q.pop();

        if (p == pq.top()) {
            answer += 1;
            pq.pop();
            
            if (idx == location)
                break;
        }
        else {
            q.push(make_pair(idx, p));
        }
    }

    return answer;
}


int main() {
    vector<int> p{1, 1, 9, 1, 1, 1};
    int loca;
    cin >> loca;
    cout << solution(p, loca) << endl;
    
    return 0;
}
