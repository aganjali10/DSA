#include <iostream>

using namespace std;

struct node{
    int data;
    node* forw;
    node* back;
};

node* head=NULL;
node* tail=NULL;

node* getnewnode(int info){
    node* newnode=new node;
    newnode->data=info;
    newnode->forw=newnode->back=NULL;
    return newnode;
}

void create(){
    cout<<"Enter data\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    head=tail=newnode;
    cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter data\n";
        cin>>info;
        newnode=getnewnode(info);
        tail->forw=newnode;
        newnode->back=tail;
        tail=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
    }

}

void insert_beg(){
    if(head==NULL&&tail==NULL){
        cout<<"Enter data\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    head=tail=newnode;
    }
    else{
        int info;
        cout<<"Enter data\n";
        cin>>info;
        node* newnode=getnewnode(info);
        head->back=newnode;
        newnode->forw=head;
        head=newnode;
    }
}

void insert_pos(node* pos){
    cout<<"Enter data\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    newnode->forw=pos->forw;
    newnode->back=pos;
    (pos->forw)->back=newnode;
    pos->forw=newnode;
}

void insert_end(){
    if(head==NULL&&tail==NULL){
        cout<<"Enter data\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    head=tail=newnode;
    }
    else{
        int info;
        cout<<"Enter data\n";
        cin>>info;
        node* newnode=getnewnode(info);
        tail->forw=newnode;
        newnode->back=tail;
        tail=newnode;
    }

}

void delete_beg(){
    node* temp=head;
    (head->forw)->back=NULL;
    head=head->forw;
    delete temp;
}

void delete_pos(node* pos){
    (pos->back)->forw=pos->forw;
    (pos->forw)->back=pos->back;
    delete pos;
}

void delete_end(){
    node* temp=tail;
    (tail->back)->forw=NULL;
    tail=tail->back;
    delete temp;
}

void display_forw(){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->forw;
    }
    cout<<endl;
}

void display_back(){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->back;
    }
    cout<<endl;
}

int main()
{
    create();
    insert_beg();
    insert_pos((head->forw)->forw);
    insert_end();
    delete_beg();
    delete_pos((tail->back)->back);
    delete_end();
    display_forw();
    display_back();
    return 0;
}
