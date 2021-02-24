#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int arr[1001] {0, };

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    set<int> s;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            s.insert(numbers[i] + numbers[j]);
        }
    }

    answer.assign(s.begin(), s.end());
    
    return answer;
}


int main() {
    vector<int> number;

    number.push_back(5);
    number.push_back(0);
    number.push_back(2);
    number.push_back(7);
    

    for (int i = 0; i < solution(number).size(); i++) {
        cout << solution(number)[i] << " ";
    }

    return 0;
}