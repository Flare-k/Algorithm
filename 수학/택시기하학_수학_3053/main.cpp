#include <cmath>
#include <iostream>
#define PI 3.1415926535897932
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   long double r;
   cin >> r;

   cout << fixed;
   cout.precision(6);
   cout << powl(r, 2) * PI << '\n';
   cout << powl(r, 2) * 2 << '\n';

   return 0;
}