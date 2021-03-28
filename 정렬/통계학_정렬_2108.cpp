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

int n, input, sum = 0;
vector<int> arr;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        // 만약 a의 cnt가 b의 cnt보다 크다면
        return true;
    }
    else if (a.first == b.first) {
        // 만약 a의 cnt와 b의 cnt가 같다면 값을 오름차순으로 정렬한다.
        if (a.second < b.second) return true;
    }  

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        sum += input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());
    
    int minN = arr.front();  // arr의 최소값
    int maxN = arr.back();   // arr의 최대값

    /* 최소 빈도값 구하기*/
    int idx = 1;
    int cnt = 1;
    vector<pair<int, int> > res;  // res(중복횟수, 값)
    int temp = arr[0];
    
    while (idx != (arr.size() + 1)) {
        if (arr[idx] == temp) {  // temp의 값과 arr[idx]의 값이 같으면 중복이므로
            cnt++; // cnt를 증가시킨다.
        } 
        else {
            res.push_back({cnt, temp});  // 만약 다음 arr[idx]값과 다르다면 현재의
                                        // cnt와 temp 값을 res에 저장한다.
            temp = arr[idx];  // 현재의 arr[idx]를 temp에 갱신한다.
            cnt = 1;
        }
        idx++;
    }

    sort(res.begin(), res.end(), comp);  // 중복횟수가 높은 순으로 정렬하고, 중복횟수가 같다면
                    // 오름차순으로 정렬한다.
    int ans = 0;
    
    if (res.size() == 1) {  //만약 하나의 수만 입력했다면 res에도 하나만 저장되어있을 것이다.
        ans = res[0].second;
    }
    else {
        if (res[0].first == res[1].first) {  // 중복 횟수가 같은 원소가 존재하면
            ans = res[1].second;// 2번째 원소의 temp를 출력
        }
        else {  //그렇지 않으면 첫번째의 temp 출력
            ans = res[0].second;
        }
    }

    cout << round(sum / (double)n) << endl;  //산술평균
    cout << arr[round(n / 2)] << endl;       //중앙값
    cout << ans << endl;                     //최소빈도값
    cout << maxN - minN << endl;             // 범위

    return 0;
}