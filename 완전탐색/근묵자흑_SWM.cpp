#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    float n, m;
    vector<int> answer;
    cin >> n >> m;  //m만큼씩 바꿔야 함
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        answer.push_back(num);
    }

    float result = ceil((answer.size() - 1) / (m - 1));
    
    cout << result << endl;
    
    return 0;
}
