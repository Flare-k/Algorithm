#include <iostream>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // UP이면 스타트 업데이트, DOWN이면 엔드 업데이트

    int n;
    cin >> n;

    int start = 1, end = 1;
    int num;
    string upDown;

    while (n--) {
        cin >> num >> upDown;

        if (upDown == "UP" && num >= end) {
            cout << "ERROR";
            return 0;
        }
        
        if (upDown == "DOWN" && num <= start) {
            cout << "ERROR";
            return 0;
        }

        if (upDown == "UP") start = num + 1;
        else end = num - 1;
        

        if (start == end) {
            cout << start;
            return 0;
        }
    }

    cout << start << " ~ " << end;

    return 0;
}