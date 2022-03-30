#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> arr;
vector<int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    arr.resize(N);
    cnt.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i  < N; i++) {
        double maxx = -21e8;
        for (int j = i + 1; j < N; j++) {
            double level = (double)(arr[j] - arr[i]) / (j - i);
			if (level > maxx) {
				cnt[i]++;
				cnt[j]++;
				maxx = level;
			}
        }
    }

    int answer = *max_element(cnt.begin(), cnt.end());
    cout << answer << '\n';

    return 0;
}