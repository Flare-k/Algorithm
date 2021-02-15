#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

/*
선발 시험은 1차, 2차 시험으로 나뉜다. 1, 2차 시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발

<입력>
테스트 케이스 수
각 테스트 케이스의 지원자 수
지원자의 서류 성적, 면접 성적의 순위
*/

void init() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
}

int main() {
    init();

    int T;
    cin >> T;

    while (T--) {
        int seeker;
        cin >> seeker;

        vector<pair<int, int>> scores;
        int first, second;

        for (int i = 0; i < seeker; i++) {
            cin >> first >> second;
            scores.push_back({first, second});
        }

        sort(scores.begin(), scores.end());

        int res = 1;
        int tmp = scores[0].second;

        for (int i = 1; i < scores.size(); i++) {
            if (scores[i].second < tmp) {
                res++;
                tmp = scores[i].second;

                if (tmp == 1) break;    // 면접성적이 1위보다 좋은 경우는 없음
            }
        }

        cout << res << '\n';
    }

    return 0;
}