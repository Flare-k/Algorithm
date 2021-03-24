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

    string res = "######____";

    int start = 0;
    int end = res.length() - 1;
    int mid;

    int maxIdx = -1;
    while (1) {
        mid = (start + end) / 2;

        if (start > end) {
            cout << (maxIdx + 1) * 10 << "%";
            break;
        }

        if (res[mid] == '#') {
            maxIdx = max(mid, maxIdx);
            start = mid + 1;
        }
        else if (res[mid] == '_') {
            end = mid - 1;
        }
    }

    return 0;
}