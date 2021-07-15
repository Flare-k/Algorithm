#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
입력
전체 테스트 케이스 개수

1. 수행할 함수
2. 배열에 들어가는 수의 개수
3. 배열
*/

vector<int> arr;

void split(string s) {
    int left = 0, right = 0;

    while (1) {
        right = s.find(',', left);

        if (right == -1) {
            arr.push_back(stoi(s.substr(left)));
            break;
        }
        else {
            arr.push_back(stoi(s.substr(left, right - left)));
            left = right + 1;
        }
    }
}

bool pFunc(string p, int& s, int& e, int& cnt) {
    for (char ch : p) {
        if (ch == 'R') {
            int tmp = s;
            s = e;
            e = tmp;
        }
        else if (ch == 'D') {
            cnt--;
            if (cnt < 0) return false;
            
            if (s < e) s++;
            else s--;
        }
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    string p;
    int ct;
    string str;

    while (t--) {
        arr.clear();

        cin >> p >> ct >> str;
        
        // []제거
        str = str.substr(1);    // [ 제거
        str.pop_back();         // ] 제거
        if (str.length() > 0) split(str);  // 벡터에 숫자넣기
        
        int s = 0, e = arr.size() - 1;
        int cntt = arr.size();

        if (pFunc(p, s, e, cntt)) {
            cout << '[';

            if (s <= e && cntt != 0) {
                for (int i = s; i < e; i++) {
                    cout << arr[i] << ',';
                }
                cout << arr[e];
            }
            else if (s >= e && cntt != 0) {
                for (int i = s; i > e; i--) {
                    cout << arr[i] << ',';
                }
                cout << arr[e];
            }

            cout << ']' << '\n';
        }
        else {
            cout << "error" << '\n';
        }
    }

    return 0;
}