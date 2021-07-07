#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(string s) {

    vector<int> tmp;
    
    // split
    int right = 0;
	int left = 0;
	while (1) {
		right = s.find(' ', left);
		if (right == -1) {
			tmp.push_back(stoi(s.substr(left)));
			break;
		}
		
		tmp.push_back(stoi(s.substr(left, right - left)));
		left = right + 1;
	}

    sort(tmp.begin(), tmp.end());

    string answer = to_string(tmp.front()) + ' ' + to_string(tmp.back());

    return answer;
}

int main() {
    string ans = solution("-1 -2 -3 -4");

    cout << ans;

    return 0;
}