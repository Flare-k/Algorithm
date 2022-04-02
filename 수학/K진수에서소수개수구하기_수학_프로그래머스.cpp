#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

vector<ll> vec;

bool sosu(ll num) {
    if (num < 2) return false;
    int a = (int) sqrt(num);

    for (int i = 2; i <= a; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

string change(int n, int k) {
    string tmp = "";

    while (n != 0) {
        tmp += to_string(n % k);
        n /= k;
    }

    reverse(tmp.begin(), tmp.end());

    return tmp;
}

int solution(int n, int k) {
    string tmp = change(n, k);

    regex re("([1-9]+)");

    auto begin = sregex_iterator(tmp.begin(), tmp.end(), re);
    auto end = sregex_iterator();

    for (auto iter = begin; iter != end; ++iter) {
        smatch match = *iter;
        vec.push_back(stoll(match.str()));
    }
    
    int answer = 0;
    for (ll num : vec) {
        if (sosu(num)) answer++;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << solution(110011, 10) << '\n';

    return 0;
}
