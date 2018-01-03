#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

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
    head=getnewnode(info);
    cout<<"Want to add mores nodes?(y/n)";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter data\n";
        cin>>info;
        node* newnode=getnewnode(info);
        newnode->next=head;
        head=newnode;
        cout<<"Want to add more nodes?(y/n)";
        cin>>c;
    }
}

void display(){
    node* p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

node* shifting(node* root){
    node* head=root;
    int k=head->data;
    while(head->next!=NULL){
        head->data=(head->next)->data;
        head=head->next;
    }
    head->data=k;
    return root;
}

int main()
{
    create();
    display();
    head=shifting(head);
    display();
    return 0;
}
