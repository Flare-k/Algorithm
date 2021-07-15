#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    
    int mingap = arr[1] - arr[0];
    
    for (int i = 2; i < n; i++) {
        mingap = gcd(mingap, arr[i] - arr[i - 1]);
    }

    int cnt = 0;
    for (int i = arr.front(); i <= arr.back(); i += mingap) cnt++;

    cout << cnt - arr.size();

    return 0;
}