#include <iostream>

using namespace std;

int a,b,c,d;

void multiply(int arr1[][],int arr2[][]){
    if(b!=c)
        return;
    int** arr3=new int*[a];
    for(int i=0;i<a;i++)
        arr3[i]=new int[d];
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            int sum=0;
            for(int k=0;k<b;k++)
                sum+=arr1[i][k]*arr2[k][j];
                arr3[i][j]=sum;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++)
            cout<<arr3[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    cout << "Enter the number of rows and columns of first matrix\n";
    cin>>a>>b;
    int** arr1=new int*[a];
    for(int i=0;i<a;i++)
        arr1[i]=new int[b];
    cout<<"Enter the matrix\n";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)
            cin>>arr1[i][j];
    }
    cout << "Enter the number of rows and columns of second matrix\n";
    cin>>c>>d;
    int** arr2=new int*[c];
    for(int i=0;i<c;i++)
        arr2[i]=new int[d];
    cout<<"Enter the matrix\n";
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++)
            cin>>arr2[i][j];
    }
    multiply(*arr1,*arr2);
    return 0;
}
