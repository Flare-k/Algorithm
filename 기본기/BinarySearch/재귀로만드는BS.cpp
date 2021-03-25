#include <iostream>
using namespace std;

int vec[10] = {4, 4, 5, 7, 8, 10, 20, 22, 23, 24};

char binarySearch(int s, int e, int tar) {
    int mid = (s + e) / 2;

    char res;

    if (s > e) {
        return 'X';
    }

    if (vec[mid] == tar) {
        return 'O';
    }

    if (vec[mid] < tar) {
        res = binarySearch(mid + 1, e, tar);
    }
    else {
        res = binarySearch(s, mid - 1, tar);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tar;
    cin >> tar;

    cout << binarySearch(0, 9, tar);

    return 0;
}