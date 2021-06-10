#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int arr[27];
    fill(arr, arr + 27, 0);

    string str;
    while (cin >> str && str != "") {

        for (char s : str) {
            if (s == ' ') continue;
            if (s >= 'a' && s <= 'z') arr[s - 'a']++;
        }
        str.clear();
    }

    int maxElem = -21e8;
    string alphabet; 
    for (int i = 0; i < 27; i++) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
            alphabet = 'a' + i;
        }
        else if (arr[i] == maxElem) {
            alphabet += 'a' + i;
        }
    }


    cout << alphabet;

    return 0;
}