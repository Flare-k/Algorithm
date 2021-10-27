#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<pair<int, string>, int>& a, pair<pair<int, string>, int>& b) {
    if (a.first.first == b.first.first)  //나이가 같으면
        return a.second < b.second;     //먼저 입력.. 즉, 인덱스가 작은 사람이 출력
    return a.first.first < b.first.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    
    vector<pair<pair<int, string>, int>> pnt;

    for (int i = 0; i < n; i++) {
        int a;
        string b;

        cin >> a >> b;
        pnt.push_back(make_pair(make_pair(a, b), i + 1));
    }

    sort(pnt.begin(), pnt.end(), compare);
    
    for (int i = 0; i < n; i++) {
        cout << pnt[i].first.first << " " << pnt[i].first.second << '\n';
    }
    
    return 0;
}
