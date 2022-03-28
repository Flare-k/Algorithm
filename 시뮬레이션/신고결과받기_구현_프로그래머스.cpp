#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>
using namespace std;

using edge = tuple<string, string>;
set<edge> st;
map<string, vector<string>> mm;
map<string, int> m;

vector<string> parsing(string r) {
	int left = 0, right = 0;
    vector<string> vec;

	while (1) {
		right = r.find(' ', left);
		if (right == -1) {
			vec.push_back(r.substr(left));
			break;
		}

		vec.push_back(r.substr(left, right - left));
		left = right + 1;
	}

    return vec;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    for (string r : report) {
        vector<string> tmp = parsing(r);
        string from = tmp.front();
        string to = tmp.back();

        if (st.find({from, to}) != st.end()) continue;

        m[to]++;
        mm[from].push_back(to);
        st.insert({from, to});
    }

    vector<int> answer;

    for (string id : id_list) {
        int cnt = 0;

        for (int i = 0; i < mm[id].size(); i++) {
            if (m[mm[id][i]] >= k) cnt++;
        }

        answer.push_back(cnt);
    }

    return answer;
}

// 확인용 main
int main() {

    vector<int> sol = solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2);

    for (int num : sol) {
        cout << num << ' ';
    }
    
    cout << '\n';

    return 0;
}