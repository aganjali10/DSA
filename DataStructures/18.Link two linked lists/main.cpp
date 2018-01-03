#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head1=NULL;
node* head2=NULL;

node* getnewnode(int info){
    node* newnode=new node;
    newnode->next=NULL;
    newnode->data=info;
}

void create1(){
    cout<<"Enter info\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    head1=newnode;
    cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter info\n";
        cin>>info;
        newnode=getnewnode(info);
        node* save=head1;
        head1=newnode;
        newnode->next=save;
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
    }
}

void create2(){
    cout<<"Enter info\n";
    int info;
    cin>>info;
    node* newnode=getnewnode(info);
    head2=newnode;
    cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter info\n";
        cin>>info;
        newnode=getnewnode(info);
        node* save=head2;
        head2=newnode;
        newnode->next=save;
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
    }
}

void display1(){
    if(head1==NULL)
        return;
        node* temp=head1;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void display2(){
    if(head2==NULL)
        return;
        node* temp=head2;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void link(){
    node* temp=head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head2;
}

void display(){
    if(head1==NULL)
        return;
        node* temp=head1;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    create1();
    display1();
    create2();
    display2();
    link();
    display();
    return 0;
}
