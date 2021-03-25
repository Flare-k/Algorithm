#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void binarySearch(int seconds, string book, vector<string> books) {
    int s = 0;
    int e = books.size() - 1;
    
    bool flag = false;
    bool check = false;

    while (seconds--) {
        int mid = (s + e) / 2;

        if (s > e) flag = true;

        if (books[mid] == book) {
            cout << "pass" << '\n';
            check = true;
            break;
        }

        if (s == e) flag = true;

        if (books[mid] < book) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    // 없거나 제한시간내에 못찾은 경우
    if (flag || !check) cout << "fail" << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> books(n);

    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    sort(books.begin(), books.end());

    
    int clients;
    cin >> clients;

    string book;
    int seconds;

    for (int i = 0; i < clients; i++) {
        cin >> book >> seconds;
        binarySearch(seconds, book, books);
    }

    return 0;
}