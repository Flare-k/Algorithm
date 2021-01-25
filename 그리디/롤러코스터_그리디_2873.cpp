#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    int arr[1000][1000];
    string res = "";

    // 행이 홀수인 경우
    if (r % 2) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - 1; j++) {
                if (i % 2 == 0) 
                    res += "R";
                else 
                    res += "L";
            }
            if (i != r - 1) 
                res += "D";
        }
    } 
    else {  // 행이 짝수인 경우
        if (c % 2) {
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < r - 1; j++) {
                    if (i % 2 == 0)
                        res += "D";
                    else
                        res += "U";
                }

                if (i != c - 1) 
                    res += "R";
            }
        } 
        else {
            int minScore = 987654321;
            pair<int, int> minPair; // 검은 칸이면서 지나지 말아야 할 지점

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cin >> arr[i][j];

                    // 검은 칸이고 최소 점수 | (i + j) % 2인 이유? 흰색 -> 검은색으로 가는 지점이 (i + j) % 2 == 1일때 이다.
                    if ((i + j) % 2 && minScore > arr[i][j]) {
                        minScore = arr[i][j];
                        minPair = {i, j};
                    }
                }
            }

            // 지나지 말아야 할 좌표의 최좌측으로 내려오고
            int newR = minPair.first % 2 ? minPair.first - 1 : minPair.first;
            for (int i = 0; i < newR; i++) {
                for (int j = 0; j < c - 1; j++) {
                    if (i % 2 == 0)
                        res += "R";
                    else
                        res += "L";
                }
                res += "D";
            }

            // 지나지 말아야 할 좌표의 대각선 아래까지 이동하고(↙)
            int newC = minPair.second;
            for (int i = 0; i < newC; i++) {
                if (i % 2 == 0)
                    res += "DR";
                else
                    res += "UR";
            }

            // 지나지 말아야 할 좌표의 최우측으로 이동
            for (int i = newC; i < c -1; i++) {
                if (i % 2 == 0)
                    res += "RD";
                else
                    res += "RU";
            }

            // 목적지까지
            if (minPair.first % 2 == 0)
                newR = r - (minPair.first + 2);
            else
                newR = r - (minPair.first + 1);

            for (int i = 0; i < newR; i++) {
                res += "D";
                for (int j = 0; j < c - 1; j++) {
                    if (i % 2 == 0)
                        res += "L";
                    else
                        res += "R";
                }
            }
        }
    }

    cout << res << '\n';
    return 0;
}