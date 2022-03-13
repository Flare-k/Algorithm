#include <iostream>
#include <algorithm>
#include <string>
#define MAX 101
using namespace std;

string cache[MAX][MAX];

string sumBigNum(string a, string b) {
    long long sum = 0;
    string result;

    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        
        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

string combination(int n, int r) {
    if (n == r || r == 0) return "1";

    string &result = cache[n][r];

    if (result != "") return result;

    result = sumBigNum(combination(n - 1, r - 1), combination(n - 1, r));   // 파스칼 삼각형

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // nCm = n!/m!(n-m)!
    int n, m;
    cin >> n >> m;
    
    cout << combination(n, m) << '\n';

    return 0;
}