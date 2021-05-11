#include <iostream>
#include <string>
using namespace std;

// sort 쓰지말고 while로 두 배열을 정렬시키기

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    char num = '1';
    
    int idxA = 0, idxB = 0;
    string answer = "";

    while (idxA != a.length() || idxB != b.length()) {
        while (a[idxA] == num) {
            answer += a[idxA++];
        }

        while (b[idxB] == num) {
            answer += b[idxB++];
        }

        num += 1;
    }

    cout << answer;

    return 0;
}