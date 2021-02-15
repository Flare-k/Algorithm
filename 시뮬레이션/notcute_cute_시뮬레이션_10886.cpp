#include <iostream>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int n;
    cin >> n;


    int zero = 0;
    int one = 0;
    while (n--) {
        int cute;
        cin >> cute;

        if (cute == 0)  zero++;
        else one++;
    }

    if (zero > one) {
        cout << "Junhee is not cute!";
    }
    else {
        cout << "Junhee is cute!";
    }

    return 0;
}