#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<string> vec;

void split() {
	
	int right = 0;
	int left = 0;
	while (1) {
		right = str.find(' ', left);
		if (right == -1) {
			vec.push_back(str.substr(left));
			break;
		}
		
		vec.push_back(str.substr(left, right - left));
		left = right + 1;
	}

}
