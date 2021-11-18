// 단순하게 푸는 경우!
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int cnt = 0;

    while (a != 1) {
        if (a % b == 0) a /= b;
        else a -= 1;
        
        cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}