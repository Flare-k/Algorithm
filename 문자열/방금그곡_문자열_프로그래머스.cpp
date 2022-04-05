#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int maxx = -21e8;
struct Node {
    int length;
    string title, music;
};

vector<Node> music_list;
map<string, char> m;

void init() {
    m["C"] = 'C'; m["C#"] = 'c'; 
    m["D"] = 'D'; m["D#"] = 'd';
    m["B"] = 'B'; m["E"] = 'E';
    m["F"] = 'F'; m["F#"] = 'f';
    m["G"] = 'G'; m["G#"] = 'g';
    m["A"] = 'A'; m["A#"] = 'a';
}

string convertMusic(string tmp) {
    string answer = "";

    for (int i = tmp.length() - 1; i >= 0; i--) {
        string t = "";
        if (tmp[i] == '#') {
            t += tmp[i - 1];
            t += "#";
            answer += m[t];
            i--;
        }
        else {
            t += tmp[i];
            answer += t;
        }
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

void split(string infos) {
    vector<string> vec;
    int left = 0, right = 0;

    while (1) {
		right = infos.find(',', left);
		if (right == -1) {
			vec.push_back(infos.substr(left));
			break;
		}
		
		vec.push_back(infos.substr(left, right - left));
		left = right + 1;
	}

    int s = stoi(vec[0].substr(0, 2)) * 60 + stoi(vec[0].substr(3));
    int e = stoi(vec[1].substr(0, 2)) * 60 + stoi(vec[1].substr(3));

    string title = vec[2];
    string music = convertMusic(vec[3]);

    music_list.push_back({e - s, title, music});
}

string solution(string m, vector<string> musicinfos) {
    init(); // map

    for (string music : musicinfos) {
        split(music);
    }

    m = convertMusic(m);
    
    string answer = "";

    for (Node music : music_list) {
        int time_diff = music.length;
        string tmp = "";
        int len = music.music.length();

        for (int i = 0; i < time_diff; i++) {
            tmp += music.music[i % len];
        }

        if (tmp.find(m) != -1) {
            if (maxx < music.length) {
                maxx = music.length;
                answer = music.title;
            }
        }
        
    }

    if (answer.length() == 0) answer = "(None)";
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string m = "CC#BCC#BCC#BCC#B";
    vector<string> musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};

    string answer = solution(m, musicinfos);

    cout << answer << '\n';

    return 0;
}