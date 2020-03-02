#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    int num;
    cin>>num;
    queue<int> q;
    string command;
    
    for(int i=0; i<num; i++){
        cin>>command;
        if(command == "push"){
            int random;
            cin>>random;
            q.push(random);
        }
        if(command == "front"){
            if(q.size() != 0){
                cout<<q.front()<<'\n';
            }
            else
                cout<<-1<<'\n';
        }
        if(command == "pop"){
            if(!q.empty()){
                cout<<q.front()<<'\n';
                q.pop();
            }
            else
                cout<<-1<<'\n';
        }
        if(command == "empty"){
            if(q.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
        if(command == "back"){
            if(!q.empty())
                cout<<q.back()<<'\n';
            else
                cout<<-1<<'\n';
        }
        if(command == "size"){
            cout<<q.size()<<'\n';
        }
    }
    
    
    return 0;
}
