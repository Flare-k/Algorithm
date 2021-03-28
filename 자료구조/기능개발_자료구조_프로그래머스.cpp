#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;

    for (int i = 0; i < progresses.size(); ++i) {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}

int main() {
    vector<int> progresses{93, 30, 55};
    vector<int> speeds{1, 30, 5};
    
    for (int i = 0; i < solution(progresses, speeds).size(); i++) {
        cout << solution(progresses, speeds)[i] << ' ';
    }

    cout << '\n';
    return 0;
}
