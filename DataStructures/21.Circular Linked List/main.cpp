#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* p=NULL;

node* getnewnode(int info){
    node* newnode=new node;
    newnode->data=info;
    newnode->next=NULL;
    return newnode;
}

void create(){
    cout<<"Enter data\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    p=newnode;
    p->next=p;
    cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter data\n";
        cin>>info;
        newnode=getnewnode(info);
        newnode->next=p->next;
        p->next=newnode;
        p=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
    }
}

void insert(){
    if(p==NULL){
        cout<<"Enter data\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    p=newnode;
    p->next=p;
    }
    else{
            int info;
    node* newnode;
        cout<<"Enter data\n";
        cin>>info;
        newnode=getnewnode(info);
        newnode->next=p->next;
        p->next=newnode;
        p=newnode;
    }
}

void display(){
    node* q=p->next;
    node* t=q;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=q);
    cout<<endl;
}

int main()
{
    create();
    display();
    insert();
    insert();
    display();
    return 0;
}
