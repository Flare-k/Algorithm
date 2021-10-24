#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> m;

void init() {
    for (int i = 100; i > 0; i -= 5) {
        for (int j = i - 1; j > i - 5; j--) {
            m[j] = i;
        }
    }
}

vector<int> gradingStudents(vector<int> grades) {
    init();
    vector<int> answer;
    for (int grade : grades) {
        int diff = abs(grade - m[grade]);

        if (grade < 38) answer.push_back(grade);
        else if (diff < 3) answer.push_back(m[grade]);
        else answer.push_back(grade);
    }

    return answer;
}


int main() {

    vector<int> grades = {73, 67, 38, 33};
    gradingStudents(grades);

    return 0;
}