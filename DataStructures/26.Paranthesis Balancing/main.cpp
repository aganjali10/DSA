#include <iostream>

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
        top=newnode;}
        else{
         node* newnode=getnewnode(info);
        node* save=top;
        top=newnode;
        newnode->next=save;}
}

char pop(){
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
        if(exp[i]=='(')
            push('(');
        else{
            if(top==NULL){
                cout<<"NO"; return 0;
            }
            pop();
        }
    }
    if(top==NULL)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
