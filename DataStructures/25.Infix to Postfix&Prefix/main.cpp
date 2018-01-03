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
        top=newnode;
    }
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

int getrank(char ch){
    switch(ch){
    case '^':
        return 4;
    case '/':
    case '*':
        return 3;
    case '-':
    case '+':
        return 2;
    case '(':
        return 1;
    }
}

int main()
{
    string result;
    string problem;
    getline(cin,problem);
    int n=problem.length();
    for(int i=0;i<n;i++){
        if((problem[i]=='^')||(problem[i]=='/')||(problem[i]=='*')||(problem[i]=='+')||(problem[i]=='-')||(problem[i]=='(')){
            if(top==NULL||problem[i]=='(')
                push(problem[i]);
                else if(getrank(top->data)<getrank(problem[i]))
                    push(problem[i]);
                else{
                    while(top!=NULL&&getrank(top->data)>=getrank(problem[i])){
                        char p=pop();
                        result.push_back(p);
                    }
                    push(problem[i]);
                }
        }
        else if(problem[i]==')'){
            char p;
            while(top!=NULL&&((p=pop())!='('))
                    result.push_back(p);
        }
        else{
            result.push_back(problem[i]);
        }
    }
        while(top!=NULL)
            result.push_back(pop());
    cout<<result<<endl;


    string result1;
    string rev;
    for(int i=0;i<n;i++)
        rev.push_back(problem[n-i-1]);
    for(int i=0;i<n;i++){
        if(rev[i]=='(')
           rev[i]=')';
        else if(rev[i]==')')
            rev[i]='(';
    }
    for(int i=0;i<n;i++){
        if((rev[i]=='^')||(rev[i]=='/')||(rev[i]=='*')||(rev[i]=='+')||(rev[i]=='-')||(rev[i]=='(')){
            if(top==NULL||rev[i]=='(')
                push(rev[i]);
                else if(getrank(top->data)<getrank(rev[i]))
                    push(rev[i]);
                else{
                    while(top!=NULL&&getrank(top->data)>=getrank(rev[i])){
                        char p=pop();
                        result1.push_back(p);
                    }
                    push(rev[i]);
                }
        }
        else if(rev[i]==')'){
            char p;
            while(top!=NULL&&((p=pop())!='('))
                    result1.push_back(p);
        }
        else{
            result1.push_back(rev[i]);
        }
    }
        while(top!=NULL)
            result1.push_back(pop());
            for(int i=0;i<n;i++)
                rev[i]=result1[n-1-i];
        cout<<rev;
            return 0;
}
