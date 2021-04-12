#include <iostream>
#include <vector>
using namespace std;

vector<int> hang;
int hn;

int path[100];
int cnt;

int calc() {
	int a = hang[0];
	int b = 0;
	int ret;

	for (int i = 1; i < hn; i++) {
		b = hang[i];
		int type = path[i - 1];
		if (type == 0) ret = (a - b) * (a + b);
		if (type == 1) {
			ret = a;
			if (a < b) ret = b;
		}
		if (type == 2) ret = (a * a) - (b * b);
		if (type == 3) ret = (a + b) * (a + b);

		a = ret;
	}

	return ret;
}

void run(int level) {

	if (level == hn - 1) {
		int ret = calc();
		if (ret == 100) cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		path[level] = i;
		run(level + 1);
		path[level] = 0;
	}
}

int main() {

	cin >> hn;
    
	for (int i = 0; i < hn; i++) {
		int a;
		cin >> a;
		hang.push_back(a);
	}

	run(0);
	cout << cnt;

	return 0;
}