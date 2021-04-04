#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<string> baem;

void split() {
	
	int right = 0;
	int left = 0;
	while (1) {
		right = str.find('#', left);
		if (right == -1) {
			baem.push_back(str.substr(left));
			break;
		}
		
		baem.push_back(str.substr(left, right - left + 1));
		left = right + 1;
	}

}

int main() {
	//str = "#~~~~~~~#~~~~#";
	cin >> str;

	//1. #을 기준으로 split
	split();

	//2. ~ 개수 cnt
	int cnt = 0;
	int maxCnt = 0;
	for (int i = 0; i < baem.size(); i++) {
		cnt = 0;
		for (int x = 0; x < baem[i].length(); x++) {
			if (baem[i][x] == '~') cnt++;
		}
		if (maxCnt < cnt) maxCnt = cnt;
	}

	for (int i = 0; i < maxCnt; i++) cout << "~";

	return 0;
}