#include <iostream>

using namespace std;

#define MAX 10

int top1=-1;
int top2=MAX;

int stack[MAX];

void push1(int value){
    if(top1==top2-1){
        cout<<"Stack full\n";
        return;
    }
    top1++;
    stack[top1]=value;
}

void push2(int value){
    if(top1==top2-1){
        cout<<"Stack full\n";
        return;
    }
    top2--;
    stack[top2]=value;
}

int pop1(){
    if(top1==-1){
        cout<<"Stack empty\n";
        return -1;
    }
    int value=stack[top1];
    top1--;
    return value;
}

int pop2(){
    if(top2==MAX){
        cout<<"Stack empty\n";
        return -1;
    }
    int value=stack[top2];
    top2++;
    return value;
}

void display(){
    if(top1==-1&&top2==MAX){
        cout<<"Stack empty\n";
        return;
    }
    cout<<"The first stack is\n";
    for(int i=top1;i>=0;i--)
        cout<<stack[i]<<endl;
    cout<<"The second stack is\n";
    for(int i=top2;i<MAX;i++)
        cout<<stack[i]<<endl;
}

int main()
{
    int n;
    cout<<"Enter\n1 for addition to stack1\n2 for deletion from stack1\n3 for addition to stack2\n4 for deletion form stack2\n5 for display\n6 for exit\n";
    cin>>n;
    while(n!=4){
        switch(n){
            case 1:{
                cout<<"Enter item\n";
                int value;
                cin>>value;
                push1(value);
                break;
            }
            case 2:{
                int value;
                value=pop1();
                cout<<value<<" is deleted\n";
                break;
            }
            case 3:{
                cout<<"Enter item\n";
                int value;
                cin>>value;
                push2(value);
                break;
            }
            case 4:{
                int value;
                value=pop2();
                cout<<value<<" is deleted\n";
                break;
            }
            case 5:{
                display();
                break;
            }
            case 6:{
                return 0;
            }
        }
       cout<<"Enter\n1 for addition to stack1\n2 for deletion from stack1\n3 for addition to stack2\n4 for deletion form stack2\n5 for display\n6 for exit\n";
    cin>>n;
    }
    return 0;
}
