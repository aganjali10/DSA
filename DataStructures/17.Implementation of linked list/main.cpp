#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

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
        head=newnode;
        cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    while(c=='y'){
        cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        node* save=head;
        head=newnode;
        newnode->next=save;
        cout<<"Want to enter more nodes?(y/n)\n";
        cin>>c;
    }
}

void insert_beg(){
        cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        node* save=head;
        head=newnode;
        newnode->next=save;
}

void insert_end(){
        cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
}

void insert_pos(node* pos){
    cout<<"Enter info\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        node* save=pos->next;
        pos->next=newnode;
        newnode->next=save;
}

void delete_beg(){
    node* temp=head;
    head=head->next;
    delete temp;
}

void delete_end(){
    node* temp=head;
        while((temp->next)->next!=NULL)
            temp=temp->next;
        node* temp2=temp->next;
        temp->next=NULL;
        delete temp2;
}

void delete_pos(node* pos){
    node* temp=head;
    while(temp->next!=pos)
            temp=temp->next;
    temp->next=pos->next;
    delete pos;
}

void display(){
    if(head==NULL)
        return;
        node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int countnodes(){
    int count=0;
    node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void reverse(){
    node* head2;
    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    head2=temp;
    node* temp1;
    while(temp!=head){
            temp1=head;
        while(temp1->next!=temp)
            temp1=temp1->next;
        temp->next=temp1;
        temp=temp1;
    }
    temp->next=NULL;
    head=head2;
}

void swapping(node* i, node* j){
    int temp=i->data;
    i->data=j->data;
    j->data=temp;
}

void sorting(){
    node* i;
    node* j;
    for(i=head;(i->next)!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if((i->data)>(j->data))
                swapping(i,j);
        }
    }
}

int main()
{
    create();
    int n;
    while(1){
            cout<<"\n1.insert_beg2.insert_end3.insert_pos4.delete_beg5.delete_end6.delete_pos7.display8.count9.reverse10.sorting11.exit\n";
    cin>>n;
        switch(n){
            case 1:{insert_beg();
            break;}
            case 2:{insert_end();
            break;}
            case 3:{insert_pos((head->next)->next);
            break;}
            case 4:{delete_beg();
            break;}
            case 5:{delete_end();
            break;}
            case 6:{delete_pos((head->next)->next);
            break;}
            case 7:{display();
            break;}
            case 8:{int count=countnodes(); cout<<count<<endl;
            break;}
            case 9:{reverse();
            break;}
            case 10:{sorting();
            break;}
            case 11:return 0;
        }
        }
}
