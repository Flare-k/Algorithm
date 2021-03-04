#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int check(char alpha) {
    if (alpha == 'A') return 0;

    int minNum = min(alpha - 'A', 'Z' + 1 - alpha);

    return minNum;
}


int solution(string name) {
    int answer = 0;
    int len = name.length();
    
    string compString(len, 'A');

    int i = 0;
    while (compString != name) {
        compString[i] = name[i];
        answer += check(name[i]);   // 커서를 위아래로 바꿔서 최소로 나오는 경우

        // 커서를 좌우로 움직여야 하는 경우
        // 오른쪽으로 가는게 빠른지, 왼쪽으로 가는게 빠른지 구해야 함.
        for (int j = 1; j < len; j++) {
            if (compString[(i + j) % len] != name[(i + j) % len]) {
                i = (i + j) % len;
                answer += j;
                break;
            }
            else if (compString[(i + len - j) % len] != name[(i + len - j) % len]) {
                i = (i + len - j) % len;
                answer += j;
                break;
            }
        }

    }

    return answer;
}

// A B C D E F G H I J K L M
// N O P Q R S T U V W X Y Z
int main() {
    
    cout << solution("JEROEN") << '\n'; // 9, 4, 5, 2, 4, 1
    cout << solution("JAN") << '\n';
    cout << solution("JAZ") << '\n';

    return 0;
}