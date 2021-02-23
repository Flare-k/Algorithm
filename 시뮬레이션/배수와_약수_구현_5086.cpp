#include <iostream>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    // 첫 번째 숫자가 두 번째 숫자의 약수라면 factor
    // 첫 번째 숫자가 두 번째 숫자의 배수라면 multiple
    // 둘 다 아니라면 neither

    int first, second;

    while (1) {
        cin >> first >> second;

        if (first == 0 && second == 0) break;

        if (second % first == 0) {
            cout << "factor" << '\n';
        }
        else if (first % second == 0) {
            cout << "multiple" << '\n';
        }
        else {
            cout << "neither" << '\n';
        }
    }

    return 0;
}