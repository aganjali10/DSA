#include <iostream>

using namespace std;

#define MAX 10

int queue[MAX];

int front=-1;
int rear=-1;

void push(int value){
    if((front==0&&rear==MAX-1)||(front==rear+1)){
        cout<<"Queue full";
        return;
    }
    if(front==-1&&rear==-1)
        front=rear=0;
    else if(front!=0&&rear==MAX-1)
        rear=0;
    else
        rear++;
    queue[rear]=value;
}

int pop(int direction){
    if(front==-1&&rear==-1)
    {
        cout<<"Queue empty\n";
        return -1;
    }
    if(direction==0){
    int value=queue[front];
    if(front==rear)
        front=rear=-1;
    else if(front==MAX-1)
        front=0;
    else front++;
    return value;
    }
    else{
        int value=queue[rear];
        if(front==rear)
            front=rear=-1;
        else if(rear==0)
            rear=MAX-1;
        else
            rear--;
        return value;
    }
}

void display(){
    if(front==-1)
    {
        cout<<"Queue empty\n";
        return;
    }
    cout<<"The queue is\n";
    if(front<=rear)
    for(int i=front;i<=rear;i++)
        cout<<queue[i]<<endl;
    else
    {
        for(int i=front;i<MAX;i++)
            cout<<queue[i]<<endl;
        for(int i=0;i<=rear;i++)
            cout<<queue[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter\n1 for addition to queue\n2 for deletion\n3 for display\n4 for exit\n";
    cin>>n;
    while(n!=4){
        switch(n){
            case 1:{
                cout<<"Enter item\n";
                int value;
                cin>>value;
                push(value);
                break;
            }
            case 2:{
                cout<<"Enter direction : 0 for front deletion and 1 for rear deletion\n";
                int direction;
                cin>>direction;
                int value;
                value=pop(direction);
                cout<<value<<" is deleted\n";
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                return 0;
            }
        }
       cout<<"Enter\n1 for addition to queue\n2 for deletion\n3 for display\n4 for exit\n";
    cin>>n;
    }
    return 0;
}
