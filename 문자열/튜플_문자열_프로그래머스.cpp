#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
    if (a.length() < b.length()) return true;
    return false;
}

int check[100001];

vector<string> split(string str) {
    vector<string> tmp;
	
	int left = 1;
	int right = 0;
	while (1) {
        left = str.find('{', left);
		right = str.find('}', right);

		if (left == -1 || right == -1) break;
		
		tmp.push_back(str.substr(left + 1, right - left - 1));
        
		left++;
        right++;
	}

    sort(tmp.begin(), tmp.end(), cmp);  // 길이에 따라 오름차순 정렬

    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> parsing = split(s);

    for (int i = 0; i < parsing.size(); i++) {
        string data = parsing[i];
    
        int left = 0, right = 0, num;
        while (1) {
            right = data.find(',', left);
            
            if (right == -1) {
                num = stoi(data.substr(left, data.length()));

                if (!check[num]) {
                    check[num] = true;
                    answer.push_back(num);
                }

                break;
            }

            num = stoi(data.substr(left, right - left + 1));
            if (!check[num]){
                check[num] = true;
                answer.push_back(num);
            }

            left = right + 1;
        }
    }

    return answer;
}

int main() {
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";

    vector<int> res = solution(s);

    for (auto& num : res) {
        cout << num << " ";
    }

    return 0;
}