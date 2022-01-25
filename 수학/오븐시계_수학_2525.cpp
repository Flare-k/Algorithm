#include <iostream>
using namespace std;

int main() {
    int hour, minutes;

    cin >> hour >> minutes;

    int add;
    cin >> add;

    minutes += add;
    
    hour += ((minutes / 60) % 24);
    minutes %= 60;

    if (hour >= 24) hour -= 24;

    cout << hour << ' ' << minutes;

    return 0;
}