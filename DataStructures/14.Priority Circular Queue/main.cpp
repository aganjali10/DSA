#include <iostream>

using namespace std;

#define MAX 10
#define priorities 10



int queue[priorities][MAX];
int front[priorities];
int rear[priorities];



void push(int priority,int value){
    if((front[priority]==0&&rear[priority]==MAX-1)||(front[priority]==rear[priority]+1)){
        cout<<"Queue full";
        return;
    }
    if(front[priority]==-1&&rear[priority]==-1)
        front[priority]=rear[priority]=0;
    else if(front[priority]!=0&&rear[priority]==MAX-1)
        rear[priority]=0;
    else
        rear[priority]++;
    queue[priority][rear[priority]]=value;
}

int pop(int priority){
    if(front[priority]==-1&&rear[priority]==-1)
    {
        cout<<"Queue empty\n";
        return -1;
    }
    int value=queue[priority][front[priority]];
    if(front[priority]==rear[priority])
        front[priority]=rear[priority]=-1;
    else if(front[priority]==MAX-1)
        front[priority]=0;
    else front[priority]++;
    return value;
}

void display(int priority){
    if(front[priority]==-1)
    {
        cout<<"Queue empty\n";
        return;
    }
    cout<<"The queue is\n";
    if(front[priority]<=rear[priority])
    for(int i=front[priority];i<=rear[priority];i++)
        cout<<queue[priority][i]<<endl;
    else
    {
        for(int i=front[priority];i<MAX;i++)
            cout<<queue[priority][i]<<endl;
        for(int i=0;i<=rear[priority];i++)
            cout<<queue[priority][i]<<endl;
    }
}

int main()
{
    for(int i=0;i<priorities;i++){
front[i]=-1;
rear[i]=-1;
}
    int n;
    cout<<"Enter\n1 for addition to queue\n2 for deletion\n3 for display\n4 for exit\n";
    cin>>n;
    while(n!=4){
        switch(n){
            case 1:{
                cout<<"Enter item and pr\n";
                int value;
                cin>>value;
                int pr;
                cin>>pr;
                push(pr,value);
                break;
            }
            case 2:{
                cout<<"Enter pr\n";
                int pr;
                cin>>pr;
                int value;
                value=pop(pr);
                cout<<value<<" is deleted\n";
                break;
            }
            case 3:{
                cout<<"Enter pr\n";
                int pr;
                cin>>pr;
                display(pr);
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
