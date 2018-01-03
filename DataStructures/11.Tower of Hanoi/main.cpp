#include <iostream>

using namespace std;

void move(int n,char a,char b,char c){
    if(n>0){
        move(n-1,a,c,b);
        cout<<a<<" to "<<c<<endl;
        move(n-1,b,a,c);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of disks to be moved from peg a to peg c\n";
    cin>>n;
    move(n,'a','b','c');
    return 0;
}
