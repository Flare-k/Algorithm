#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int maxx = -21e8;
    for (int i = 1; i < n; i++){
        if (arr[i - 1] < arr[i]) {
            sum += (arr[i] - arr[i - 1]);
        }
        else {
            maxx = max(sum, maxx);
            sum = 0;
        }
    }

    maxx = max(sum, maxx);
    cout << maxx;

    return 0;
}