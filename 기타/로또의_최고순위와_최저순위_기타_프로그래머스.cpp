#include <iostream>
#include <string>
#include <vector>
using namespace std;

int rankNums(int n) {
    if (n == 6) return 1;
    else if (n == 5) return 2;
    else if (n == 4) return 3;
    else if (n == 3) return 4;
    else if (n == 2) return 5;
    
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int ans[47] = { 0 };
    for (int num : lottos) {
        ans[num]++;
    }

    int cnt = 0;
    for (int num : win_nums) {
        if (ans[num]) cnt++;
    }

    int bestCase = ans[0] + cnt;
    int worstCase = cnt;

    answer.push_back(rankNums(bestCase));
    answer.push_back(rankNums(worstCase));

    return answer;
}

int main() {

    vector<int> input = solution({44, 1, 0, 0, 31, 25}, {31, 10, 45, 1, 6, 19});

    for (int res : input) {
        cout << res << ' ';
    }

    return 0;
}