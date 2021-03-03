#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> stk;

    for (int cur = 0; cur < prices.size(); cur++) {
        while (!stk.empty() && prices[cur] < prices[stk.top()]) {
            answer[stk.top()] = cur - stk.top();
            stk.pop();
        }
        // 현재 시간의 주식가격이 바로직전 시간보다 크다면 stack에 push
        stk.push(cur);
    }

    while (!stk.empty()) {
        answer[stk.top()] = (int)prices.size() - stk.top() - 1;
        stk.pop();
    }

    return answer;
}


// 테스트용 메인함수
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto ans = solution({1, 2, 3, 2, 3});

    for (auto sec : ans) {
        cout << sec << " ";
    }

    return 0;
}