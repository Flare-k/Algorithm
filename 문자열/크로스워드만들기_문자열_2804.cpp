#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int idxA;
    int idxB;
    bool flag = false;
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) {
                idxA = i;   // a의 열
                idxB = j;   // b의 열
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    for (int i = 0; i < b.length(); i++) {
        for (int j = 0; j < a.length(); j++) {
            if (idxB != i) {    // a와 b가 다른 지점
                if (idxA != j) cout << '.';
                else cout << b[i];  // 만나는 지점에서 세로로 출력되어야 함
            }
            else {  // a와 b가 만나는 지점
                cout << a[j];
            }
        }
        cout << '\n';
    }

    return 0;
}