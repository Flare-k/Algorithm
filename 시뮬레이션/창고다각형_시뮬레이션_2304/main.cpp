#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool visit[1001];
    
    int n; // 기둥의 개수
    cin >> n;
    vector<pair<int, int>> column;

    for (int i = 0 ; i < n; i++){
        int x, h;
        cin >> x >> h; // x: x 좌표, h: 높이
        column.push_back({x, h});
    }
    sort(column.begin(), column.end());

    int width = 0;
    
    int left_point = column[0].first;
    int left_height = column[0].second;
    for (auto& point : column){
        if (left_height <= point.second){
            width += (point.first - left_point) * left_height;
            left_point = point.first;
            left_height = point.second;
        }
    }

    int right_point = column.back().first;
    int right_height = column.back().second;
    for (int i = column.size() - 1; i >= 0; i--) {
        if (right_height < column[i].second){
            width += (right_point - column[i].first) * right_height;
            right_point = column[i].first;
            right_height = column[i].second;
        }
    }

    cout << width + left_height << endl;
    return 0;
}