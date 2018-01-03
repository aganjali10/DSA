#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* top=NULL;

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
        top=newnode;
        cout<<"Want to add more elements?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        node* save=top;
        top=newnode;
        newnode->next=save;
        cout<<"Want to enter more elements?(y/n)\n";
        cin>>c;
    }
}

void push(){
        cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        node* save=top;
        top=newnode;
        newnode->next=save;
}

int pop(){
    int value=top->data;
    node* temp=top;
    top=top->next;
    delete temp;
    return value;
}

void display(){
    if(top==NULL)
        return;
        node* temp=top;
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
