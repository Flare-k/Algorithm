#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bucketA;
vector<int> bucketB;

int main() {

    for (int i = 0; i < 2; i++) {
        int A, B;
        cin >> A >> B;

        if (i < 1) {
            bucketA.push_back(A);
            bucketA.push_back(B);
        }
        else {
            bucketB.push_back(A);
            bucketB.push_back(B);
        }
    }

    int case1 = bucketA.front() + bucketB.back();
    int case2 = bucketA.back() + bucketB.front();

    if (case1 < case2) cout << case1;
    else cout << case2;

    return 0;
}