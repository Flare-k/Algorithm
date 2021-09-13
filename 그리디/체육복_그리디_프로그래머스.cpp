#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    int suit[31] = {0, };

    for (int i = 0; i < lost.size(); i++) {
        suit[lost[i] - 1] -=  1;
    }

    for (int i = 0; i < reserve.size(); i++) {
        suit[reserve[i] - 1] += 1;
    }

    for (int i = 0; i < lost.size(); i++) {
        int idx = lost[i] - 1;
        
        if (suit[idx] == 0) continue;

        if (suit[idx - 1] == 1) {
            suit[idx - 1]--;
            suit[idx]++;
        } 
        else if (suit[idx + 1] == 1) {
            suit[idx + 1]--;
            suit[idx]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (suit[i] >= 0) answer++;
    }

    return answer;
}

int main() {
    int n;
    vector<int> l;
    vector<int> r;

    n = 5;

    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    r.push_back(1);
    r.push_back(2);
    r.push_back(3);

    // result: 4

    cout << solution(n, l, r);
}