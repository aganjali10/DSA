#include <iostream>

using namespace std;

int linearsearch(int arr[],int n,int item){
    for(int i=0;i<n;i++)
        if(arr[i]==item)
        return i;
    return -1;
}

int main()
{
    cout<<"Enter the number of elements\n";
    int n;
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the element to be searched\n";
    int item;
    cin>>item;
    cout<<"Index of element "<<linearsearch(arr,n,item);
    delete []arr;
    return 0;
}
