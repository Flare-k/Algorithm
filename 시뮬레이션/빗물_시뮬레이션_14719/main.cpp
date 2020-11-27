#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c;   // 가로, 세로 값
    cin >> r >> c;

    vector<int> col;    // 빗물이 담기는 벡터
    for (int i = 0; i < c; i++){
        int a;
        cin >> a;
        col.push_back(a);
    }

    int width = 0;
    for (int i = 1; i < c - 1; i++){
        int left = 0, right = 0;
        for (int j = 0; j < i; j++){
            left = max(left, col[j]);
        }
        for (int k = c - 1; k > i; k--) {
           right = max(right, col[k]);
        }
        // 가장 왼쪽과 가장 오른쪽 중에 큰 기둥을 선택하고
        // 그 중 작은 기둥에서 현재 위치를 빼면 얼마나 비가 찼는지 알 수 있다.
        width += max(0, min(left, right) - col[i]);
    }

    cout << width << endl;

   return 0;
}