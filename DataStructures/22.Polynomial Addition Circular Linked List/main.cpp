#include <iostream>

using namespace std;

struct node{
    int coeff;
    int exp;
    node* next;
};

node* last1=NULL;
node* last2=NULL;
node* last3=NULL;

node* getnewnode(int coefficient,int exponent){
    node* newnode=new node;
    newnode->coeff=coefficient;
    newnode->exp=exponent;
    newnode->next=NULL;
    return newnode;
}

void create1(){
    cout<<"Enter data\n";
    int coefficient,exponent;
    cin>>coefficient>>exponent;
    node* newnode=getnewnode(coefficient,exponent);
    last1=newnode;
    last1->next=last1;
    cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter data\n";
        cin>>coefficient>>exponent;
        newnode=getnewnode(coefficient,exponent);
        newnode->next=last1->next;
        last1->next=newnode;
        last1=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
    }
}

void create2(){
    cout<<"Enter data\n";
    int coefficient,exponent;
    cin>>coefficient>>exponent;
    node* newnode=getnewnode(coefficient,exponent);
    last2=newnode;
    last2->next=last2;
    cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter data\n";
        cin>>coefficient>>exponent;
        newnode=getnewnode(coefficient,exponent);
        newnode->next=last2->next;
        last2->next=newnode;
        last2=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
    }
}

void display1(){
    node* q=last1->next;
    node* t=q;
    do{
        cout<<t->coeff<<"x^"<<t->exp;
        if(t!=last1)
        cout<<"+";
        t=t->next;
    }while(t!=q);
    cout<<endl;
}

void display2(){
    node* q=last2->next;
    node* t=q;
    do{
        cout<<t->coeff<<"x^"<<t->exp;
        if(t!=last2)
            cout<<"+";
        t=t->next;
    }while(t!=q);
    cout<<"\b\b"<<endl;
}

void create3(){
    node* newnode;
    node* q1=last1->next;
    node* t1=q1;
    node* q2=last2->next;
    node* t2=q2;
    if(t1->exp==t2->exp){
        newnode=getnewnode(t1->coeff+t2->coeff,t1->exp);
        t1=t1->next;
        t2=t2->next;}
        else if(t1->exp>t2->exp){
            newnode=getnewnode(t1->coeff,t1->exp);
            t1=t1->next;}
        else{
            newnode=getnewnode(t2->coeff,t2->exp);
            t2=t2->next;}
        last3=newnode;
        last3->next=last3;
        do{
           if(t1->exp==t2->exp){
        newnode=getnewnode(t1->coeff+t2->coeff,t1->exp);
        t1=t1->next;
        t2=t2->next;}
        else if(t1->exp>t2->exp){
            newnode=getnewnode(t1->coeff,t1->exp);
            t1=t1->next;}
        else{
            newnode=getnewnode(t2->coeff,t2->exp);
            t2=t2->next;}
        newnode->next=last3->next;
        last3->next=newnode;
        last3=newnode;
        }while(t1!=q1&&t2!=q2);
        if(t1!=q1){do{
            newnode=getnewnode(t1->coeff,t1->exp);
            t1=t1->next;
            newnode->next=last3->next;
        last3->next=newnode;
        last3=newnode;
        }while(t1!=q1);
        }
        else{
        do{
            newnode=getnewnode(t2->coeff,t2->exp);
            t2=t2->next;
            newnode->next=last3->next;
        last3->next=newnode;
        last3=newnode;
        }while(t2!=q2);}
}

void display3(){
    node* q=last3->next;
    node* t=q;
    do{
        cout<<t->coeff<<"x^"<<t->exp;
        if(t!=last3)
            cout<<"+";
        t=t->next;
    }while(t!=q);
    cout<<"\b\b"<<endl;
}

int main()
{
    create1();
    display1();
    create2();
    display2();
    create3();
    display3();
    return 0;
}
