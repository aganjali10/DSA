#include <iostream>
using namespace std;

int m,n;

void add(int arr1[],int arr2[]){
    int* arr3=new int[2*(m+n)+1];
    int a=1,b=1,c=1;
    while(a<2*m&&b<2*n){
        if(arr1[a]==arr2[b]){
            arr3[c]=arr1[a];
            arr3[c+1]=arr1[a+1]+arr2[b+1];
            a+=2;
            b+=2;
            c+=2;
        }
        else if(arr1[a]>arr2[b]){
            arr3[c]=arr1[a];
            arr3[c+1]=arr1[a+1];
            a+=2;
            c+=2;
        }
        else{
            arr3[c]=arr2[b];
            arr3[c+1]=arr2[b+1];
            b+=2;
            c+=2;
        }
    }
    while(a<2*m){
        arr3[c]=arr1[a];
        arr3[c+1]=arr1[a+1];
        a+=2;
        c+=2;
    }
    while(b<2*n){
        arr3[c]=arr2[b];
        arr3[c+1]=arr2[b+1];
        b+=2;
        c+=2;
    }
    arr3[0]=c/2;
    cout<<"Number of terms "<<arr3[0]<<endl;
    for(int i=1;i<(2*(c/2)+1);i++){
    if(i%2==0)
        cout<<"Coeff "<<arr3[i]<<endl;
    else
        cout<<"Power "<<arr3[i]<<" ";
    }
}

int main()
{
    cout<<"Enter the number of terms in first polynomial\n";
    cin>>m;
    int* arr1=new int[2*m+1];
    arr1[0]=m;
    cout<<"Enter the power and coefficient resp\n";
    for(int i=1;i<2*m;i+=2)
        cin>>arr1[i]>>arr1[i+1];
    cout<<"Enter the number of terms in second polynomial\n";
    cin>>n;
    int* arr2=new int[2*n+1];
    arr2[0]=n;
    cout<<"Enter the power and coefficient resp\n";
    for(int i=1;i<2*n;i+=2)
        cin>>arr2[i]>>arr2[i+1];
    add(arr1,arr2);
    return 0;
}
