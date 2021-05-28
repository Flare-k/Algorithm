#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    
    int answer = 0;
    double range = (2 * w + 1);
    double nStation;

    nStation = (stations[0] - w - 1);
    answer += ceil(nStation / range);

    for (int i = 1; i < stations.size(); i++) {
        int pre = stations[i - 1] + w + 1;
        int cur = stations[i] - w - 1;

        answer += ceil((cur - pre + 1) / range);
    }

    nStation = n - (stations[stations.size() - 1] + w + 1) + 1;
    if (nStation >= 0) answer += ceil(nStation / range);

    
    return answer;
}

int main() {

    cout << solution(11, {4, 11}, 1) << '\n';

    return 0;
}