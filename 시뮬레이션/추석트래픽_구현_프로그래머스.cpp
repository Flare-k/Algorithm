#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    int start, end;
};

vector<Node> v;

int solution(vector<string> lines) {
    
    for (string line : lines) {
        string h, m, s, ms;
        int hour, minute, second, diff;

        line.pop_back();

        h = line.substr(11, 2);
        m = line.substr(14, 2);
        s = line.substr(17, 2);
        ms = line.substr(20, 3);
        
        hour = stoi(h) * 3600 * 1000;
        minute = stoi(m) * 60 * 1000;
        second = stoi(s) * 1000 + stoi(ms);
        diff = stof(line.substr(24, 5)) * 1000;

        v.push_back({hour + minute + second - diff + 1, hour + minute + second});
    }

    int size = lines.size();
    int answer = -21e8;
    for (int i = 0; i < size; i++) {
        int end = v[i].end + 1000;  // 1000ms = 1초
        int cnt = 0;

        for (int j = i; j < size; j++) {
            if (v[j].start < end) cnt++;
        }

        if (answer < cnt) answer = cnt;
    }

    return answer;
}

int main() {

    vector<string> lines = {"2016-09-15 20:59:57.421 0.351s",
                            "2016-09-15 20:59:58.233 1.181s",
                            "2016-09-15 20:59:58.299 0.8s",
                            "2016-09-15 20:59:58.688 1.041s",
                            "2016-09-15 20:59:59.591 1.412s",
                            "2016-09-15 21:00:00.464 1.466s",
                            "2016-09-15 21:00:00.741 1.581s",
                            "2016-09-15 21:00:00.748 2.31s",
                            "2016-09-15 21:00:00.966 0.381s",
                            "2016-09-15 21:00:02.066 2.62s"};

    int sol = solution(lines);
    cout << sol << '\n';

    return 0;
}