#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end());
    vector<int> timeTable;
    
    for (string tb : timetable) {
        int hour = stoi(tb.substr(0, 2)) * 60;
        int minute = stoi(tb.substr(3));
        timeTable.push_back(hour + minute);
    }

    int busStop = 9 * 60;
    int idx = 0;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        while (cnt < m && idx < timeTable.size()) {
            if (timeTable[idx] <= busStop) {
                cnt++;
                idx++;
            }
            else break;
        }

        if (i == n) {
            if (cnt < m) result = busStop;
            else result = timeTable[idx - 1] - 1;
        }

        busStop += t;
    }

    string hour = result / 60 < 10 ? "0" + to_string(result / 60) : to_string(result / 60);
    string minute = result % 60 < 10 ? "0" + to_string(result % 60) : to_string(result % 60);
    
    return hour + ":" + minute;
}

int main() {
    string result = solution(10, 60, 45, {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"});
    cout << result << '\n';

	return 0;
}

/*
셔틀은 09:00부터 총 n회 t분 간격으로 역에 도착하며, 하나의 셔틀에는 최대 m명의 승객이 탈 수 있다.

셔틀은 도착했을 때 도착한 순간에 대기열에 선 크루까지 포함해서 대기 순서대로 태우고 바로 출발한다. 
예를 들어 09:00에 도착한 셔틀은 자리가 있다면 09:00에 줄을 선 크루도 탈 수 있다.

> 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각을 구하여라.

          n, t, m, {timetable}
"09:00" | 1, 1, 5, {"08:00", "08:01", "08:02", "08:03"}
"09:09" | 2, 10, 2, {"09:10", "09:09", "08:00"}
"08:59" | 2, 1, 2, {"09:00", "09:00", "09:00", "09:00"}
"00:00" | 1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01"}
"09:00" | 1, 1, 1, {"23:59"}
"18:00" | 10, 60, 45, {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}

1. 만약 도착시간 내에 자리가 여유있으면 그 시간에 탈 수 있음
2. 도착시간에 m만큼 사람이 탄다면? 제일 마지막에 타는 사람보다 최소 1분전에 와서 줄서야함
3. 기준은 버스 도착시간 기준..
*/