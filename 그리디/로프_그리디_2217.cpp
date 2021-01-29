#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> arr;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    long long result = 0;

    for (int i = 0; i < n; i++) {
        long long weight = arr[i];
        
        for (int j = i + 1; j < n; j++) 
            weight += arr[i];

        result = max(result, weight);
    }

    cout << result;

   return 0;
}