#include <iostream>
#include <string>
#include <vector>

using namespace std;

// size, idx
vector<int> findMaxValue(vector<int> vec) {
    int maxx = -21e8;
    vector<int> ans;

    for (int num : vec) {
        maxx = max(maxx, num);
    }

    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == maxx) {
            cnt++;
            idx = i;
        }
    }

    ans.push_back(cnt);
    ans.push_back(idx);

    return ans;
}


vector<int> findMinValue(vector<int> vec) {
    int minn = 21e8;

    vector<int> ans;

    for (int num : vec) {
        minn = min(minn, num);
    }

    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == minn) {
            cnt++;
            idx = i;
        }
    }

    ans.push_back(cnt);
    ans.push_back(idx);

    return ans;
}

string calAvg(vector<int> vec, vector<int> exc) {
    float sum = 0;

    for (int num : vec) {
        sum += num;
    }

    if (!exc.empty()) { // 최대 또는 최소가 유일한 경우
        int idx = exc.back();
        sum -= vec[idx];
        sum /= (vec.size() - 1);
    }
    else {  // 유일하지 않은 경우
        sum /= vec.size();
    }
    
    if (sum >= 90) return "A";
    else if (sum >= 80.0f) return "B";
    else if (sum >= 70.0f) return "C";
    else if (sum >= 50.0f) return "D";
    return "F";
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    vector<int> tmp;

    for (int i = 0; i < scores.size(); i++) {
        tmp.clear();
        for (int j = 0; j < scores[0].size(); j++) {
            tmp.push_back(scores[j][i]);
        }

        vector<int> maxv = findMaxValue(tmp);
        vector<int> minv = findMinValue(tmp);

        if (maxv.front() == 1 && maxv.back() == i) {
            answer += calAvg(tmp, maxv);
        }
        else if (minv.front() == 1 && minv.back() == i) {
            answer += calAvg(tmp, minv);
        }
        else {  // 유일하지 않은 경우
            answer += calAvg(tmp, {});
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> v = {{100, 90, 98, 88, 65},
                            {50, 45, 99, 85, 77},
                            {47, 88, 95, 80, 67},
                            {61, 57, 100, 80, 65},
                            {24, 90, 94, 75, 65}};

    cout << solution(v) << '\n';

    return 0;
}