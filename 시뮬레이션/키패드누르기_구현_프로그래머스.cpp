#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;
    int leftDist = 0, rightDist = 0;

    for (int number : numbers) {
        // 왼손 초기 값
        if (number == 1 || number == 4 || number == 7) {
            left = number;
            answer += "L";
        }
        // 오른손 초기 값
        else if (number == 3 || number == 6 || number == 9) {
            right = number;
            answer += "R";
        }
        // 그외의 값
        else {
            if (number == 0) {
                number = 11;
            }

            int tmpLeft = abs(left - number);
            int tmpRight = abs(right - number);

            leftDist = (tmpLeft / 3) + (tmpLeft % 3);
            rightDist = (tmpRight / 3) + (tmpRight % 3);

            if (leftDist == rightDist) {
                if (hand == "left") {
                    left = number;
                    answer +=  "L";
                }
                else {
                    right = number;
                    answer += "R";
                }
            }
            else if (leftDist < rightDist) {
                left = number;
                answer += "L";
            }
            else {
                right = number;
                answer += "R";
            }
        }
    }

    return answer;
}

int main() {

    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");

    return 0;

}
