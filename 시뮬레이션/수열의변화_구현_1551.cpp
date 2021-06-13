#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> arr;

void split(string str) {	
	int right = 0;
	int left = 0;

	while (1) {
		right = str.find(',', left);

		if (right == -1) {
			arr.push_back(stoi(str.substr(left)));
			break;
		}
		
		arr.push_back(stoi(str.substr(left, right - left)));
		left = right + 1;
	}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;


    string seq;
    cin >> seq;

    split(seq);

    vector<int> tmp;
    while (k--) {
        tmp.clear();
        for (int i = 0; i < n - 1; i++) {
            tmp.push_back(arr[i + 1] - arr[i]);
        }

        arr = tmp;
        n = arr.size();
    }

    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ',';
    }
    cout << arr.back();


    return 0;
}