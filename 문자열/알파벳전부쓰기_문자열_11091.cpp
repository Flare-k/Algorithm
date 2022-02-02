#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    cin.ignore();
    
    for (int i = 0; i < N; i++) {
        memset(arr, 0, sizeof(arr));

        string s;
        getline(cin, s);

        for (char ch : s) {
            if (ch == ' ') continue;
            if (ch >= 'A' && ch <= 'Z') ch = tolower(ch);
            if (ch >= 'a' && ch <= 'z') arr[ch - 'a']++;
        }

        string missing = "";
        for (char c = 'a'; c <= 'z'; c++) {
            if (arr[c - 'a'] == 0) missing += c;
        }

        if (missing.length() > 0) cout << "missing " << missing << '\n';
        else cout << "pangram" << '\n';
    }

    return 0;
}