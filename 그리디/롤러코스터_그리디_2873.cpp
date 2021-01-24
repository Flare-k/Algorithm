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
            pair<int, int> minPair;

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cin >> arr[i][j];

                    if ((i + j) % 2 && minScore > arr[i][j]) {
                        minScore = arr[i][j];
                        minPair = {i, j};
                    }
                }
            }

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

            int newC = minPair.second;
            for (int i = 0; i < newC; i++) {
                if (i % 2 == 0)
                    res += "DR";
                else
                    res += "UR";
            }

            for (int i = newC; i < c -1; i++) {
                if (i % 2 == 0)
                    res += "RD";
                else
                    res += "RU";
            }

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