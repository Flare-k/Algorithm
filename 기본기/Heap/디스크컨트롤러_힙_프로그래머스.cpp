#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {    // jobs = {요청 시점, 소요시간}
    
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>> pq;  // {소요시간, 요청 시점}
    
    int sum = 0, idx = 0, time = 0;
    int req, len;

    while (idx < jobs.size() || !pq.empty()) {
        if (idx < jobs.size()) {
            req = jobs[idx][0];
            len = jobs[idx][1];
        }
        
        if (idx < jobs.size() && req <= time) {
            pq.push({-len, req});
            idx++;
            continue;
        }

        if (!pq.empty()) {
            int preq = pq.top().second;
            int plen = -pq.top().first;

            time += plen;
            sum += (time - preq);
            pq.pop();
        }
        else {
            time = req;
        }
    }

    int avg = sum / jobs.size();    

    return avg;
}

int main() {

    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};

    cout << solution(jobs) << '\n';

    return 0;
}