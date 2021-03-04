#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string oneTwoFour[3] = {"4", "1", "2"};

    while (n != 0) {
        answer = oneTwoFour[n % 3] + answer;

        if (n % 3 == 0) {
            n = n / 3 - 1;
        }
        else {
            n /= 3;
        }
    }

    return answer;
}


// 테스트용 메인함수
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(7) << '\n';
    cout << solution(8) << '\n';
    cout << solution(9) << '\n';
    cout << solution(10) << '\n';
    cout << solution(11) << '\n';
    cout << solution(12) << '\n';
    cout << solution(13) << '\n';
    cout << solution(14) << '\n';
    cout << solution(15) << '\n';

    return 0;
}