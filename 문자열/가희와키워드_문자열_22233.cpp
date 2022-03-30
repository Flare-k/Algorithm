#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<string> st;

void split(string str) {
	int right = 0;
	int left = 0;
    string tmp;
	while (1) {
		right = str.find(',', left);
		if (right == -1) {
            tmp = str.substr(left);
            if (st.find(tmp) != st.end()) st.erase(tmp);
			break;
		}
		
        tmp = str.substr(left, right - left);
        if (st.find(tmp) != st.end()) st.erase(tmp);
		left = right + 1;
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)  {
        string kw;
        cin >> kw;
        st.insert(kw);
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        split(s);

        cout << st.size() << '\n';
    }

    return 0;
}