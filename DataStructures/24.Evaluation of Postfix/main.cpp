#include <iostream>
#include<math.h>

using namespace std;

struct node{
    char data;
    node* next;
};

node* top=NULL;

node* getnewnode(char info){
    node* newnode=new node;
    newnode->next=NULL;
    newnode->data=info;
    return newnode;
}

void push(char info){
        if(top==NULL){
            node* newnode=getnewnode(info);
            top=newnode;
        }
        else{
        node* newnode=getnewnode(info);
        node* save=top;
        top=newnode;
        newnode->next=save;
        }
}

char  pop(){
    char value=top->data;
    node* temp=top;
    top=top->next;
    delete temp;
    return value;
}

int main()
{
    string exp;
    getline(cin,exp);
    int n=exp.length();
    for(int i=0;i<n;i++){
        if(exp[i]=='^'||exp[i]=='/'||exp[i]=='*'||exp[i]=='-'||exp[i]=='+'){
            int op2=pop();
            int op1=pop();
            switch(exp[i]){
            case '^':
                push((pow(op1,op2)));
                break;
            case '/':
                push((op1/op2));
                break;
            case '*':
                push((op1*op2));
                break;
            case '-':
                push((op1-op2));
                break;
            case '+':
                push((op1+op2));
                break;
            }
        }
        else{
            push(exp[i]-'0');
        }
    }
    cout<<(int)pop();
}
