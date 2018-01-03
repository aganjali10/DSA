#include <iostream>

using namespace std;

struct node{
    int coeff,exp;
    node* next;
};

node* head1=NULL;
node* head2=NULL;
node* head3=NULL;

node* getnewnode(int coeff,int exp){
    node* newnode=new node;
    newnode->next=NULL;
    newnode->coeff=coeff;
    newnode->exp=exp;
    return newnode;
}

void create1(){
    cout<<"Enter info\n";
        int coeff,exp;
        cin>>coeff>>exp;
        node* newnode=getnewnode(coeff,exp);
        head1=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter info\n";
        int coeff,exp;
        cin>>coeff>>exp;
        node* newnode=getnewnode(coeff,exp);
        node* temp=head1;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        cout<<"Want to enter more nodes?(y/n)\n";
        cin>>c;
    }
}

void create2(){
    cout<<"Enter info\n";
        int coeff,exp;
        cin>>coeff>>exp;
        node* newnode=getnewnode(coeff,exp);
        head2=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter info\n";
        int coeff,exp;
        cin>>coeff>>exp;
        node* newnode=getnewnode(coeff,exp);
        node* temp=head2;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        cout<<"Want to enter more nodes?(y/n)\n";
        cin>>c;
    }
}

void display(node* head){
    if(head==NULL)
        return;
        node* temp=head;
    while(temp!=NULL){
        cout<<temp->coeff<<"x^"<<temp->exp<<"+ ";
        temp=temp->next;
    }
}

node* insert(node* head,node* p){
    if(head==NULL){
        return p;
    }
    node* t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=p;
    return head;
}

node* add(node* h1,node* h2){
    node* c=NULL;
    while(h1!=NULL&&h2!=NULL){
        if(h1->exp==h2->exp){
            node* t=getnewnode(h1->coeff+h2->coeff,h1->exp);
            c=insert(c,t);
            h1=h1->next;
            h2=h2->next;
        }
        else if(h1->exp>h2->exp){
            node* t=getnewnode(h1->coeff,h1->exp);
            c=insert(c,t);
            h1=h1->next;
        }
        else{
            node* t =getnewnode(h2->coeff,h2->exp);
            c=insert(c,t);
            h2=h2->next;
        }
    }
    while(h1!=NULL){
        node* t=getnewnode(h1->coeff,h1->exp);
            c=insert(c,t);
            h1=h1->next;
    }
    while(h2!=NULL){
        node* t =getnewnode(h2->coeff,h2->exp);
            c=insert(c,t);
            h2=h2->next;
    }
    return c;
}

node* operation(node* t,int c,int e){
    node* k=t;
    node* t1=NULL;
    while(k!=NULL){
        node* t=getnewnode(k->coeff*c,k->exp+e);
        t1=add(t1,t);
        k=k->next;
    }
    return t1;
}

node* mul(node* t1,node* t2){
    node* c=NULL;
    while(t1!=NULL){
        node* t=operation(t2,t1->coeff,t1->exp);
        c=add(c,t);
        t1=t1->next;
    }
    return c;
}

int main()
{
    create1();
    display(head1);
    create2();
    display(head2);
    head3=mul(head1,head2);
    display(head3);
}
