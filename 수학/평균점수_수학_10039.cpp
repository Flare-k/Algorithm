#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        int score;
        cin >> score;

        if (score >= 40) sum += score;
        else sum += 40;
    }

    cout << sum / 5;
    
    return 0;
}