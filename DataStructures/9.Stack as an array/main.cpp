#include <iostream>

using namespace std;

#define MAX 10

int top=-1;

int stack[MAX];

void push(int value){
    if(top==MAX-1){
        cout<<"Stack full\n";
        return;
    }
    top++;
    stack[top]=value;
}

int pop(){
    if(top==-1){
        cout<<"Stack empty\n";
        return -1;
    }
    int value=stack[top];
    top--;
    return value;
}

void display(){
    if(top==-1){
        cout<<"Stack empty\n";
        return;
    }
    cout<<"The stack is\n";
    for(int i=top;i>=0;i--)
        cout<<stack[i]<<endl;
}

int main()
{
    int n;
    cout<<"Enter\n1 for addition to stack\n2 for deletion\n3 for display\n4 for exit\n";
    cin>>n;
    while(n!=4){
        switch(n){
            case 1:{
                cout<<"Enter item\n";
                int value;
                cin>>value;
                push(value);
                break;
            }
            case 2:{
                int value;
                value=pop();
                cout<<value<<" is deleted\n";
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                return 0;
            }
        }
       cout<<"Enter\n1 for addition to stack\n2 for deletion\n3 for display\n4 for exit\n";
    cin>>n;
    }
    return 0;
}
