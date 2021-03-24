#include <iostream>
#include <algorithm>
using namespace std;

/*
    Binary Search의 전제조건 : 정렬되어있는 리스트
    함수를 타고 타서 돌아오는 값에 뭔가 해야하는게 있으면 재귀가 좋다.
    그런게 아니라 최종지점에서 끝나는 경우이면 while이 낫다.
*/




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vec[7] = {4, 2, 4, 1, 6, 4, 8};
    sort(vec, vec + 7);

    int start = 0;
    int end = 6;
    int mid;

    int target = 6;
    while (1) {
        mid = (start + end) / 2;

        if (start > end) {
            cout << "미발견";
            break;
        }

        if (vec[mid] == target) {
            cout << "발견";
            break;
        }

        if (vec[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return 0;
}