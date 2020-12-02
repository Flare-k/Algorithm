#include <iostream>
#include <tuple>
#include <set>
#include <vector>
#include <string>
using namespace std;

int solution(string dirs) {
    int x = 0, y = 0, oldX = 0, oldY = 0, cnt = 0;

    using edge = tuple < int, int, int, int>;
    set<edge> avatar;

    for (char way : dirs){
        switch (way){
        case 'L':
            if (x > -5) x--; break;
        case 'R':
            if (x < 5) x++; break;
        case 'U':
            if (y < 5) y++; break;
        case 'D':
            if (y > -5) y--; break;
        }
        
        if (x == oldX && y == oldY) continue;
        
        avatar.insert({oldX, oldY, x, y});
        avatar.insert({x, y, oldX, oldY});
        oldX = x;
        oldY = y;
    }
    
    return avatar.size() / 2;
}