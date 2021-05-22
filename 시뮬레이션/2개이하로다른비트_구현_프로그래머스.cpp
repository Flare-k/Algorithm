#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long num : numbers) {
        if (num % 2 == 0) {
            answer.push_back(num + 1);
        }
        else {
            ll bit = 1;

            while (1) {
                if ((num & bit) == 0) break;
                bit *= 2;
            }

            bit /= 2;   // 만큼 더한 값이 최소 값
            answer.push_back(num + bit);
        }
    }

    return answer;
}

int main() {
    vector<long long> result = solution({2, 7});

    for (long long num : result) {
        cout << num << ' ';
    }

    return 0;
}