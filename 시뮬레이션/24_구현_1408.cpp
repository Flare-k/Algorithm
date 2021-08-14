#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string stime, etime;
    cin >> stime >> etime;

    int e = stoi(etime.substr(0, 2)) * 3600 + stoi(etime.substr(3, 2)) * 60 + stoi(etime.substr(6));
    int s = stoi(stime.substr(0, 2)) * 3600 + stoi(stime.substr(3, 2)) * 60 + stoi(stime.substr(6));

    int ans = e > s ? e - s : e + 24 * 3600 - s;

    int tm = ans / 60;
    int ts = ans % 60;
    int th = tm / 60;
    tm %= 60;

    string hour = th < 10 ? "0" + to_string(th) : to_string(th);
    string min = tm < 10 ? "0" + to_string(tm) : to_string(tm);
    string sec = ts < 10 ? "0" + to_string(ts) : to_string(ts);


    cout << hour << ':' << min << ':' << sec;

    return 0;
}