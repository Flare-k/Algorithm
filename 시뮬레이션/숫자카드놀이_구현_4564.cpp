#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    while (1) {
        cin >> num;

        if (num == 0) break;

        cout << num << ' ';
        
        while (num % 10 != num) {

            int tmp = 1;
            while (num != 0) {
                tmp *= num % 10;
                num /= 10;
            }
            
            num = tmp;
            cout << num << ' ';
        }

        cout << '\n';
    }


    return 0;
}