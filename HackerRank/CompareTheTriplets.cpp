#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int len = a.size();
    
    int elice = 0, bob = 0;
    
    for (int i = 0; i < len; i++) {
        if (a[i] > b[i]) elice++;
        else if (a[i] < b[i]) bob++;
        else continue;
    }
    
    return {elice, bob};
}
