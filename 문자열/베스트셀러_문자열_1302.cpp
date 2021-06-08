#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map<string, int> books;

    string book;

    while (n--) {
        cin >> book;
        books[book]++;
    }

    string answer;
    int idx = -21e8;

    map<string, int>::iterator iter;
    for (iter = books.begin(); iter != books.end(); iter++) {
        if (iter->second > idx) {
            idx = iter->second;
            answer = iter->first;
        }
    }

    cout << answer;

    return 0;
}