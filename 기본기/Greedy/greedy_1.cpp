#include <iostream>
using namespace std;

int coins[4] = {500, 100, 50, 10};


int main() {
    int target = 1350;

    int idx = 0;
    int num = 0;

    while (target != 0) {
        if (target / coins[idx] != 0)
            num += (target / coins[idx]);

        target %= coins[idx++];
    }

    cout << num;
    
    return 0;
}