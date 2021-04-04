#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int maxScore = -21e8;


void run(string s, int n, int sum) {
    for (int i = 0; i < n; i++) {
        swap(s[i + 1], s[s.length() - 1]);

        sum = 0;

        for (int j = 0; j < s.length() - 1; j++) {
            int tmpScore = abs(s[j] - s[j + 1]);

            if (tmpScore == 0) {
                sum -= 50;
            }
            else if (tmpScore > 0 && tmpScore <= 5) {
                sum += 3;
            }
            else if (tmpScore >= 20) {
                sum += 10;
            }
        }

        if (maxScore < sum) {
            maxScore = sum;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 이웃한 글자가 같은글자일때? -50
    // 2. 같은 글자는 아니지만 이웃한글자의 간격이 5이하? +3
    // 3. 이웃한 글자의 간격이 20이상? +10
    // n번 만큼 swap시 가장 점수가 클때

    string s;
    int n;

    cin >> s >> n;
    run(s, n, 0);

    cout << maxScore << '\n';

    return 0;
}