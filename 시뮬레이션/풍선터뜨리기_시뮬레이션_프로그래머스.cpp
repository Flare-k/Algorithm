#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 1;

    int s = 0;
    int e = a.size() - 1;
    int left = a[s];
    int right = a[e];

    while (s < e) {
        if (left > right) {
            s++;

            if (a[s] < left) {
                answer++;
            }

            left = min(left, a[s]);
        }
        else {
            e--;

            if (a[e] < right) {
                answer++;
            }

            right = min(right, a[e]);
        }
    }

    return answer;
}

int main() {
    int sol = solution({9, -1, -5});

    cout << sol;

    return 0;
}

// 9, -1, -5 = 3
//-16, 27, 65, -2, 58, -92, -71, -68, -61, -33 = 6