/*
 각 AP Task의 최종 Computation으로 평균지연시간을 계산해야할 경우.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<float, float>> task;    //periodic task의 computation과 period를 할당받는 변수
vector<pair<float, float>> aperiod; //Aperiodic task의 computation과 arrival time을 할당받는 변수
vector<float> aperiodIdx;           //Aperiodic task의 인덱스 위치를 할당받는 변수
vector<int> aperiodComputation;

const int MAX = 100000;
int check[MAX]; // 특정 Task의 computation을 체크하기 위한 변수.
int gcd(int a, int b);
int lcm(int a, int b);
int hyperPeriod;
bool compare(pair<float, float> c, pair<float, float> p);   // period를 기준으로 오름차순하기 위한 비교함수
bool utilization(int n, vector<pair<float, float>> task);  //utilization을 계산해주는 함수
float average_waiting_time(int n, vector<float> aperiodIdx, vector<pair<float,float>> arrivalTime);  //Average Waiting Time을 계산해주는 함수


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // ----Periodic Task--------------------------------------------------------------------------------
    float taskNum;
    cout<<"Enter the number of task [3, 5] : "; // 3~5사이의 Task 갯수 입력
    cin>>taskNum; //반드시 3~5사이의 수를 입력해야 하는 것은 아니지만 권장
    //computation, period
    for(int i=0; i<taskNum; i++){
        int computation, period;
        cout<<"\n[Task "<<i+1<<"]"<<'\n';
        cout<<"Computation: "; cin>>computation;
        cout<<"Period: "; cin>>period;
        task.push_back(make_pair(computation, period));
    }
    sort(task.begin(), task.end(), compare);  //주기로 오름차순 정렬
    
    for(int i=0; i<task.size()-1; i++){
        gcd(task[i].second, task[i+1].second);
        hyperPeriod = lcm(task[i].second, task[i+1].second);
    }
    
    int idx=0;
    for(int index=0; index < task.size(); index++){
        idx++;
        int c = task[index].first;  //Periodic task's computation time
        int p = task[index].second;  //Periodic task's period
        
        for(int i=0; i<hyperPeriod/p; i++){
            int j=0;
            int missCheck=0;
            for(int k=0; k<c; k++){
                while(check[i*p +j]){
                    j++;
                }
                if(j > p) break;    //만약 computation만큼 할당하였는데 남는다면?? 반복문 나올 것.
                check[i*p + j] = idx;
                missCheck++;
            }
            if(c != missCheck){
                cout<<"Deadline Miss!!"<<'\n';
                exit(0);
            }
        }
    }
    
    // ----Aperiodic Task--------------------------------------------------------------------------------
    int apNum;
    cout<<"\n------------------------------------------------";
    cout<<"\n\nEnter the number of Aperiodic task [1, 3] : "; // 1~3사이의 Aperiodic Task 갯수 입력
    cin>>apNum; //반드시 1~3사이의 수를 입력해야 하는 것은 아니지만 권장
    for(int i=0; i<apNum; i++){
        int computation, arrivalT;
        cout<<"\n[Aperiodic Task "<<i+1<<"]"<<'\n';
        cout<<"Computation: "; cin>>computation;
        cout<<"Arrival Time: "; cin>>arrivalT;
        aperiod.push_back(make_pair(computation, arrivalT));
    }
    sort(aperiod.begin(), aperiod.end(), compare);  //도착시간으로 오름차순 정렬
    
    for(int index=0; index < aperiod.size(); index++){
        idx++;
        int aC = aperiod[index].first;  //Aperiodic computation time
        int aT = aperiod[index].second;  //Aperiodic arrival time
        
        for(int i=aT-1; i<=hyperPeriod; i++){
            if(check[i] == false){
                check[i] = idx;
                aC--;
                if(aC == 0){
                    aperiodIdx.push_back(i);    //ap의 마지막 computation index를 저장한다.
                    break;
                }
            }
        }
    }
    for(int i=0; i<aperiod.size(); i++){
        for(int j=0; j<aperiod[i].first; j++){
            aperiodComputation.push_back(aperiod[i].second);
        }
    }
    
    
     cout<<"\n\n--------------Background ASP RESULT--------------\n";
    if (utilization(taskNum, task) == 1)
        cout<<" Utilization condition is satisfied."<<'\n';
    else
        cout<<" Utilization condition is not satisfied."<<'\n';
    cout<<" Average Waiting Time of Aperiodic Task: "<<average_waiting_time(apNum, aperiodIdx, aperiod)<<'\n';
    cout<<"\n--------------   [ Gannt Chart ]   --------------\n";
    cout<<'|';
    for(int i=0; i<hyperPeriod; i++){
        if(check[i] > task.size()){
            cout<<"AP"<<'|';
        }
        else{
            cout<<check[i]<<'|';
        }
    }
    cout<<"\n-------------------------------------------------\n";
    
    return 0;
}


int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}


bool compare(pair<float, float> c, pair<float, float> p){
    if(c.second > p.second)
        return false;
    return true;
}
bool utilization(int n, vector<pair<float, float>> task) {
    float sum = 0.0;
    
    for (int i = 0; i < n; i++)
        sum += (task[i].first / task[i].second);    // sum += c[i]/p[i]
    cout<<" SUM: "<<sum<<'\n'<<" U <= n * ( 2^(1/n) - 1 ): "<<float(n)*float(pow(2.0, float(1.0 / n)) - 1.0)<<'\n';
    if (sum <= float(n) * float(pow(2.0, float(1.0 / n)) - 1.0))
        return 1;
    else
        return 0;
}
float average_waiting_time(int n, vector<float> aperiodIdx, vector<pair<float, float>> arrivalTime) {
    float sum = 0;
    for (int i = 0; i < n; i++){
        sum += (aperiodIdx[i] - arrivalTime[i].second); // aperiod - arrival Time
    }
    float result = sum / n;
    return result;
}
