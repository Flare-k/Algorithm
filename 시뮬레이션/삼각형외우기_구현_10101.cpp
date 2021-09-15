#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    int sixty = 0;
    int num;
    for (int i = 0; i < 3; i++) {
        cin >> num;
        m[num]++;

        if (num == 60) sixty++;
        sum += num;
    }

    int cnt = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->first != 0) cnt = max(cnt, iter->second);
    }

    if (sixty == 3) cout << "Equilateral";
    else if (sum == 180 && cnt == 2) cout << "Isosceles";
    else if (sum == 180 && cnt == 1) cout << "Scalene";
    else if (sum != 180) cout << "Error";

    return 0;
}