#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> A(10);
    vector<int> B(10);

    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < 10; i++) {
        cin >> B[i];
    }
    
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        if (A[i] > B[i]) a++;
        else if (A[i] < B[i]) b++;
    }

    if (a > b) cout << "A" << '\n';
    else if (a < b) cout << "B" << '\n';
    else cout << "D" << '\n';

    return 0;
}