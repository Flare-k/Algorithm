#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
/*
예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가
된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가
여러 개인 자연수도 있을 수 있다.

자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

216 -> 198

예측이라기 보다는.. 일정 자릿수부터 시작해서 전수조사해야할듯..
*/

int n;
const int MAX = 1000000 + 1;


void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }

    for (int i = n / 2; i <= n; i++) {
        int sum = 0;
        int initial = i;

        sum += initial;

        while (initial) {
            sum += initial % 10;
            initial /= 10;
        }
        
        arr[i] = sum;
    }


    int cnt = 0;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (arr[i] == n) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    
    if (ans.size()) {
        cout << ans[0] << endl;
    } 
    else {
        cout << 0 << endl;
    }

    
    return 0;
}