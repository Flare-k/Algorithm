#include <iostream>
#include <string>
using namespace std;


class Stack{
private:
    int stack[10000];
    int length = 0;
public:
    Stack(){}
    ~Stack(){}
    
    void push(int data){
        stack[length] = data;
        length++;
    }

    void pop(){
        if(empty())
            cout<<-1<<'\n';
        else{
            cout<<stack[length-1]<<'\n';
            stack[length-1] = 0;
            length--;
        }
    }
    
    int size(){
        return length;
    }

    int empty(){
        if(length == 0)
            return 1;
        else
            return 0;
    }
    
    int top(){
        if(empty())
            return -1;
        else
            return stack[length-1];
    }

};

int main(){
    int num;
    string command;
    int insert;
    
    cin>>num;
      
    Stack stack;
    
    for(int i=0; i<num; i++){
        cin>>command;
        
        if(command == "push"){
            cin>>insert;
            stack.push(insert);
        }
        
        if(command == "pop"){
            stack.pop();
        }
        if(command == "size"){
            cout<<stack.size()<<'\n';
        }
        if(command == "empty"){
            cout<<stack.empty()<<'\n';
        }
        if(command == "top"){
            cout<<stack.top()<<'\n';
        }
    }
    
    return 0;
}
