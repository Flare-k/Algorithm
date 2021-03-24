#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
    Parmetric Search Algorithm
*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char res[10][11] = { 
        "##########",
        "##########",
        "##########",
        "##########",
        "##########",
        "##########",
        "###_______",
        "__________",
        "__________",
        "__________"
    };
    // *참고. (6, 2) 까지 쓰였음

    int start = 0;
    int end = 9;
    int mid;

    int dx = 0, dy = 0;
    while (1) {
        mid = (start + end) / 2;

        if (start > end) break;

        if (res[mid][0] == '#') {
            dx = max(dx, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    start = 0;
    end = 9;
    while (1) {
        mid = (start + end) / 2;

        if (start > end) break;

        if (res[dx][mid] == '#') {
            dy = max(dy, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << dx << ", " << dy;

    return 0;
}