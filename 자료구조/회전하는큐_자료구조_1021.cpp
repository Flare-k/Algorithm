#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> dq;

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    vector<int> dir;
    int num;
    for (int i = 0; i < M; i++) {
        cin >> num;
        dir.push_back(num);
    }

    int total = 0;
    int idx = 0;
    while (M != 0) {
        int target = dir[idx];
        
        if (dq.front() == target) {
            dq.pop_front();
            idx++;
            M--;
        }

        int left = 0;
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] != target)  left++;
            else break;
        }

        int right = dq.size() - left;

        if (left < right) {
            total += left;

            while (left--) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
        }
        else {
            total += right;

            while (right--) {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
        }
    }
    
    cout << total;

    return 0;
}