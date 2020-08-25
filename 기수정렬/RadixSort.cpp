#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#define endl "\n"
#define MAX 100
using namespace std;

int Max_Value;
int Arr[MAX];
bool Flag[10001];
queue<int> Q[10];

void Print() {
   cout << "###################################################################"
           "#################################################"
        << endl;
   int Cnt = 0;
   for (int i = 0; i < MAX; i++) {
      printf("%6d ", Arr[i]);
      Cnt++;
      if (Cnt == 20) {
         Cnt = 0;
         cout << endl;
      }
   }
   cout << "###################################################################"
           "#################################################"
        << endl;
   cout << endl;
}

void Radix_Sort() {
   int Radix = 1;
   while (1) {
      if (Radix >= Max_Value) break;
      Radix = Radix * 10;
   }  // 최대자릿수만큼 10씩 곱한다. 만약 Max_Value가 1234라면 Radix는 10000이
      // 됨
   for (int i = 1; i < Radix; i = i * 10) {
      for (int j = 0; j < MAX; j++) {
         int K;
         if (Arr[j] < i)
            K = 0;
         else
            K = (Arr[j] / i) % 10;
         Q[K].push(Arr[j]);
      }

      int Idx = 0;
      for (int j = 0; j < 10; j++) {
         while (Q[j].empty() == 0) {
            Arr[Idx] = Q[j].front();
            Q[j].pop();
            Idx++;
         }
      }
   }
}

int main(void) {
   srand((unsigned)time(NULL));
   for (int i = 0; i < MAX;) {
      Arr[i] = (rand() % 10000) + 1;
      if (Flag[Arr[i]] == false) {
         Flag[Arr[i]] = true;
         if (Max_Value < Arr[i]) Max_Value = Arr[i];

         i++;
      }
   }

   cout << "[ Initialize Array State ] " << endl;
   Print();
   Radix_Sort();
   cout << "[ After Sort Array State ] " << endl;
   Print();

   return 0;
}
