#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool checkOper(char ch, int diff, int num) {
    if (ch == '=') return diff == num;
    else if (ch == '>') return diff > num;
    else return diff < num;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string kakaoFriends = "ACFJMNRT";

    do {
        bool flag = true;
        for (string d : data) {
            char a = d[0];
            char b = d[2];
            char op = d[3];
            int range = d[4] - '0';

            int diff = kakaoFriends.find(a) - kakaoFriends.find(b);
            int distance = abs(diff) - 1;

            if (checkOper(op, distance, range)) continue;
            flag = false;
            break;
        }
        
        if (flag) answer++;

    } while(next_permutation(kakaoFriends.begin(), kakaoFriends.end()));


    return answer;
}

int main() {

    cout << solution(2, {"N~F=0", "R~T>2"}) << '\n';

    return 0;
}