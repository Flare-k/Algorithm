#include <vector>
#include <iostream>
using namespace std;

int used[1001];
vector<int> res;

// 조합
void run(int level, int start, int sum, vector<int> nums) {
    if (level == 3) {
        res.push_back(sum);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (used[i] == 1) continue;

        used[i] = 1;
        run(level + 1, i, sum + nums[i], nums);
        used[i] = 0;
    }
}

int solution(vector<int> nums) {
    int answer = 0;

    run(0, 0, 0, nums);

    for (int r : res) {
        int cnt = 0;
        for (int i = 2; i < 10001; i++) {
            if (r % i == 0) cnt++;  // 소수 처리
        }

        if (cnt == 1) answer++; // 0으로 나눠떨어지는게 1을 제외하고 하나라면 answer 증가
    }

    return answer;
}

int main() {
    //cout << solution({1, 2, 3, 4}) << '\n';     // 1
    cout << solution({1, 2, 7, 6, 4}) << '\n';  // 4
    return 0;
}