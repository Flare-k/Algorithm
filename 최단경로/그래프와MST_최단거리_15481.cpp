#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int u, v, w;
};

struct Compare {
    bool operator() (Node A, Node B) const {
        return A.w < B.w;
    }
};

int N, M;
set<Node, Compare> st;
unordered_map<int, int> m;
vector<Node> vec;

int main() {
    
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        st.insert({u, v, w});
        vec.push_back({u, v, w});
    }

    int level = N - 1;
    for (auto _vec : vec) {
        int cnt = 0;
        int sum = 0;


        
    }
    
    return 0;
}