#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* front=NULL;
node* rear=NULL;

node* getnewnode(int info){
    node* newnode=new node;
    newnode->next=NULL;
    newnode->data=info;
    return newnode;
}

void create(){
    cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        front=rear=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        rear->next=newnode;
        rear=newnode;
        cout<<"Want to enter more nodes?(y/n)\n";
        cin>>c;
    }
}

void push(){
        cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        if(front==NULL&&rear==NULL)
            front=rear=newnode;
        else{
        rear->next=newnode;
        rear=newnode;}
}

int pop(){
    int value=front->data;
    node* temp=front;
    if(front==rear)
        front=rear=NULL;
    else
    front=front->next;
    delete temp;
    return value;
}

void display(){
    if(front==NULL)
        return;
        node* temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    create();
    int n;
    cout<<"1.add2.delete3.display4.exit\n";
    cin>>n;
    while(n<=4){
        switch(n){
            case 1:{push();
            break;}
            case 2:{cout<<pop()<<" is deleted\n";
            break;}
            case 3:{display();
            break;}
            case 4:return 0;
        }
        cout<<"1.add2.delete3.display4.exit\n";
        cin>>n;
    }
    return 0;
}
