#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int head = 0;
    int tail = people.size() - 1;

    while (head <= tail) {
        if (people[head] + people[tail] <= limit) {
            head++;
            tail--;
        }
        else {
            tail--;
        }
        answer++;
    }

    return answer;
}

int main() {
    cout << solution({70, 50, 80, 50}, 100) << "\n";
    cout << solution({70, 80, 50}, 100) << "\n";
    return 0;
}