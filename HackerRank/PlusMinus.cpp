#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    int total = arr.size();

    double pst = 0, ngt = 0, zero = 0;

    for (int num : arr) {
        if (num > 0) pst++;
        else if (num < 0) ngt++;
        else zero++;
    }

    cout << fixed;
    cout.precision(6);

    cout << pst / total << '\n' << ngt / total << '\n' << zero / total;

}