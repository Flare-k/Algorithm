#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<float> ans;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ans.push_back(num);
    }
    sort(ans.begin(), ans.end());

    float maxNum = ans.back();
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans[i];
    }

    cout << fixed;
    cout.precision(2);
    cout << (sum / n) / maxNum * 100 << endl;
    
    return 0;
}