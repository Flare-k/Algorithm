#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles) {
    sort(candles.begin(), candles.end(), greater<int>());
    int maxHeight = candles.front();
    
    int cnt = 0;
    for (int c : candles) {
        if (c != maxHeight) break;
        cnt++;
    }
    
    return cnt;
}
