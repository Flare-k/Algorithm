#include <iostream>
#include <string>
using namespace std;

const int MAX = 10000 + 1;
int arr[MAX];

void erathosthenes() {
    arr[0] = 0;
    arr[1] = 0;
    
    for (int i = 2; i <= MAX; i++) {
        arr[i] = i;
    }

    for (int i = 2; i <= MAX; i++) {
        if (arr[i] == 0) continue;
        for (int j = i + i; j <= MAX; j += i) {
            arr[j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    erathosthenes();

    string a = "1033";
    string b = "8179";

    int idx = 0;
    int cnt = 0;
    while (a != b) {
        
        int tmp = a[idx % 4] - '0';
        string s = a;
        string saveS;

        for (int i = tmp + 1; i <= 9; i++) {
            s[idx % 4] = i + '0';

            if (arr[stoi(s)] == stoi(s)) saveS = s;
        }

        if (saveS.length() != 0) {
            a = saveS;
            cnt++;
            cout << a << '\n';
        }

        idx++;
    }

    return 0;
}