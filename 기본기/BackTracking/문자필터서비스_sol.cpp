#include <iostream>
#include <string>
using namespace std;

string war[5] = { "chicken", "pizza", "jockbal", "bread", "samhap" };
string vect;

int isSame(string war, int index)
{
	for (int i = 0; i < war.length(); i++) {
		if (war[i] != vect[index + i]) return 0;
	}
	return 1;
}

int check(int index)
{
	for (int i = 0; i < 5; i++) {
		if (index + war[i].length() > vect.length()) continue;

		if (isSame(war[i], index) == 1) {
			return i;
		}
	}

	return -1;
}

void changeCh(string& vect)
{
	for (int i = 0; i < vect.length(); i++) {
		if (vect[i] >= 'A' && vect[i] <= 'Z') vect[i] = vect[i] - 'A' + 'a';
	}
}

int main()
{
	string result;
	string input;
	
	cin >> input;
	vect = input;

	changeCh(vect); //대소문자 변경

	for (int i = 0; i < vect.length(); i++) {
		int ret = check(i);

		if (ret == -1) {
			result += input[i];
		}
		else {
			result += "###";
			i += war[ret].length() - 1;
		}
	}

	cout << result;

	return 0;
}