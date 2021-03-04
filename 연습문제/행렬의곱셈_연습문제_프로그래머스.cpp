#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j < arr2[0].size(); j++) {
            int sum = 0;
            for (int k = 0; k < arr1[i].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            tmp.push_back(sum);
        }
        answer.push_back(tmp);
    }

    return answer;
}


int main() {
    vector<vector<int>> arr1{{1, 4},
                            {3, 2},
                            {4, 1}};
    vector<vector<int>> arr2{{3, 3},
                            {3, 3}};

    for (int i = 0; i < solution(arr1, arr2).size(); i++) {
        for (int j = 0; j < solution(arr1, arr2)[0].size(); j++) {
            cout << solution(arr1, arr2)[i][j] << " ";
        }
        cout << '\n';
    } 


    return 0;    
}