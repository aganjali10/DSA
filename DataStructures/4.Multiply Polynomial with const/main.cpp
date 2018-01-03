#include <iostream>

using namespace std;

int m;

void multiply(int arr1[],int value){
    for(int i=1;i<2*m;i++)
        arr1[i+1]*=value;
}

int main()
{
    cout<<"Enter the number of terms in the polynomial\n";
    cin>>m;
    int* arr1=new int[2*m+1];
    arr1[0]=m;
    cout<<"Enter the power and coefficient resp\n";
    for(int i=1;i<2*m;i+=2)
        cin>>arr1[i]>>arr1[i+1];
    cout<<"Enter the constant to be multiplied\n";
    int value;
    cin>>value;
    multiply(arr1,value);
    for(int i=0;i<2*m+1;i++)
        cout<<arr1[i]<<" ";
    return 0;
}
