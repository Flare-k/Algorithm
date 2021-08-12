#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    vector<int> tmp;

    for (int i = 0; i < scores.size(); i++) {
        int sum = 0, size = scores.size();
        int maxx = 0, minn = 0;

        for (int j = 0; j < scores[0].size(); j++) {
            if (scores[j][i] < scores[i][i]) maxx++;
            if (scores[j][i] > scores[i][i]) minn++;

            sum += scores[j][i];
        }

        if ((maxx == size - 1) || (minn == size - 1)) {
            sum -= scores[i][i];
            size--;
        }

        double avg = (double)sum / (double) size;

        if (avg >= 90.0f) answer += "A";
        else if (avg >= 80.0f) answer += "B";
        else if (avg >= 70.0f) answer += "C";
        else if (avg >= 50.0f) answer += "D";
        else answer += "F";
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