#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string time) {
    int len = time.length();

    string check = time.substr(len - 2);
    
    string hours = "";
    int h;

    if (check == "AM") {
        hours = time.substr(0, 2);
        h = stoi(hours);

        if (h == 12) {
            hours = "00" + time.substr(2, len - 4);
        }
        else {
            hours = time.substr(0, len - 2);
        }
    }
    else if (check == "PM") {
        hours = time.substr(0, 2);
        h = stoi(hours);

        if (1 <= h && h <= 11) {
            h += 12;
            hours = to_string(h) + time.substr(2, len - 4);
        }
        else {
            hours = time.substr(0, len - 2);
        }
    }

    return hours;
}
