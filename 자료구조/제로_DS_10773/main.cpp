#include <iostream>
#include <stack>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   stack<int> price;
   // 만약 0을 불렀다면 이전 수 pop
   int K;
   cin >> K;
   for (int i = 0; i < K; i++) {
      int n;
      cin >> n;
      if (n != 0)
         price.push(n);
      else
         price.pop();
   }
   int sum = 0;
   while(!price.empty()){
       sum += price.top();
       price.pop();
   }
   cout << sum;
   return 0;
}