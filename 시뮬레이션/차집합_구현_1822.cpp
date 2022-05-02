#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int a, b;
map<int, bool> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b;

    vector<int> arr(a, 0);
    int num;

    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < b; i++) {
        cin >> num;
        m[num] = true;
    }

    vector<int> answer;
   
    for (int i = 0; i < a; i++) {
        if (m.count(arr[i])) continue;
        answer.push_back(arr[i]);
    }

    cout << answer.size() << '\n';
    
    for (int n : answer) {
        cout << n << ' '; 
    }

    return 0;
}