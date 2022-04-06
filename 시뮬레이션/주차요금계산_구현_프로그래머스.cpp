#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

struct Node {
    int accu;
    int cur;
    string status;
};

map<string, Node> info;
set<string> car_list;

vector<int> solution(vector<int> fees, vector<string> records) {
    for (auto& record : records) {
        stringstream ss(record);
        string time, car, status;
        ss >> time >> car >> status;
        
        int curtime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
        car_list.insert(car);

        if (status == "OUT") {
            info[car].accu += (curtime - info[car].cur);
            info[car].cur = curtime;
            info[car].status = status;
        }
        else if (status == "IN"){
            if (info.count(car) == false) info[car] = {0, curtime, status};
            else info[car] = {info[car].accu, curtime, status};
        }
    }

    int time = 23 * 60 + 59;
    vector<string> tmp;
    for (auto car : car_list) {
        tmp.push_back(car);
        if (info[car].status == "OUT") continue;

        info[car].accu += time - info[car].cur;
        info[car].cur = time;
        info[car].status = "OUT";
    }

    sort(tmp.begin(), tmp.end());

    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    vector<int> answer;

    for (string car : tmp) {
        if (info[car].accu < defaultTime) {
            answer.push_back(defaultFee);
            continue;
        }
        
        int usingTime = ceil(double (info[car].accu - defaultTime) / unitTime) * unitFee;
        answer.push_back(defaultFee + usingTime);
    }

    return answer;
}

int main() {
	vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int> sol = solution(fees, records);

    for (int num : sol) {
        cout << num << ' ';
    }

	return 0;
}


/*
주차장의 요금표와 차량이 들어오고(입차) 나간(출차) 기록이 주어졌을 때, 차량별로 주차 요금을 계산
기본 시간(분)	기본 요금(원)	단위 시간(분)	단위 요금(원)
    180	            5000	        10          	600

=기본요금 + (누적이용시간 - 기본시간) / 단위 시간 * 단위 요금
* 누적이용시간이 기본시간 이하? 기본요금으로 계산
*/