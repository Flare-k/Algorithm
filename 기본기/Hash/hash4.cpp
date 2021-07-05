#include <iostream>
#include <unordered_map>
using namespace std;

// -10 ~ 10 중 가장많이 등장하는 숫자 출력

unordered_map<int, int> um;

int main() {

    um[-7]++;
    um[5]++;
    um[3]++;
    um[2]++;
    um[-5]++;
    um[-7]++;
    um[-9]++;
    um[-7]++;

    int maxx = -21e8;
    int num;
    for (int i = -10; i <= 10; i++) {
        if (um.count(i)) {
            if (maxx < um[i]) {
                maxx = um[i];
                num = i;
            }
        }
    }

    cout << num << '\n';

    return 0;
}