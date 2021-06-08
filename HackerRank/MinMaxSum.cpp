#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    long long minSum = 0, maxSum = 0;
    
    sort(arr.begin(), arr.end());
    int size = arr.size();
    
    for (int i = 0; i < 4; i++) {
        minSum += arr[i];
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < 4; i++) {
        maxSum += arr[i];
    }
    
    cout << minSum << ' ' << maxSum << '\n';
}