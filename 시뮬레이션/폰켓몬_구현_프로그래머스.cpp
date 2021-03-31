#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    set<int> s;

    for (int num : nums) {
        s.insert(num);
    }

    return min(s.size(), nums.size() / 2);
}

int main() {
    cout << solution({3, 1, 2, 3}) << '\n';          // 2
    cout << solution({3, 3, 3, 2, 2, 4}) << '\n';    // 3
    cout << solution({3, 3, 3, 2, 2, 2}) << '\n';    // 2
}