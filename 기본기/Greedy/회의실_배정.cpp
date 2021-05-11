#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int from;
    int to;
};

bool compare(Node& a, Node& b) {
    if (a.to < b.to) return true;
    else if (a.to > b.to) return false;
    return a.from < b.from;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<Node> meetingRoom;

    int from, to;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        meetingRoom.push_back({from ,to});
    }

    sort(meetingRoom.begin(), meetingRoom.end(), compare);

    int start = 0;
    int cnt = 0;

    for (int i = 0; i < meetingRoom.size(); i++) {
        if (meetingRoom[i].from >= start) {
            cnt++;
            start = meetingRoom[i].to;
        }
    }

    cout << cnt;

    return 0;
}