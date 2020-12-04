#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;
/*
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는
경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고,
kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가
떨어져서 나타나기 때문에 그룹 단어가 아니다.
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int group = 0;
    int n;
    bool visit[26] = {0, };
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int j;
        visit[int(s[0]) - 97] = true;
        
        for (j = 1; j < s.length(); j++) {
            if (s[j-1] != s[j]) {
                if (!visit[int(s[j]) - 97])
                    visit[int(s[j]) - 97] = true;
                else 
                    break;
            }
        }

        if (j == s.length()) group++;
        
        memset(visit, false, sizeof(visit));
    }

    cout << group;
    
    return 0;
}
/*
a = 97
A = 65
32차이
*/