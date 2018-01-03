#include <iostream>

using namespace std;

int m,n;

int main()
{
    cout<<"Enter number of rows and columns\n";
    cin>>m>>n;
    int** arr=new int*[m];
    for(int i=0;i<m;i++)
        arr[i]=new int[n];
        int count=0;
    cout<<"Enter the elements\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                count++;
        }
    }
    int** sparse=new int*[count+1];
    for(int i=0;i<count+1;i++)
        sparse[i]=new int[4];
    for(int i=0;i<count+1;i++)
        sparse[i][0]=i;
    sparse[0][1]=m;
    sparse[0][2]=n;
    sparse[0][3]=count;
    int ptr=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                sparse[ptr][1]=i;
                sparse[ptr][2]=j;
                sparse[ptr][3]=arr[i][j];
                ptr++;
            }
        }
    }
    cout<<"The sparse matrix is\n";
    for(int i=0;i<count+1;i++){
        for(int j=0;j<4;j++)
            cout<<sparse[i][j]<<"\t";
        cout<<endl;
    }
    int** transpose=new int*[count+1];
    for(int i=0;i<count+1;i++)
        transpose[i]=new int[4];
    for(int i=0;i<count+1;i++)
        transpose[i][0]=i;
        transpose[0][1]=sparse[0][2];
        transpose[0][2]=sparse[0][1];
        transpose[0][3]=sparse[0][3];
        int* s=new int[n];
        int* t=new int[n];
        for(int i=0;i<n;i++)
            s[i]=0;
        for(int i=1;i<count+1;i++)
            s[sparse[i][2]]++;
        t[0]=1;
        for(int i=1;i<n;i++)
            t[i]=t[i-1]+s[i-1];
        for(int i=1;i<count+1;i++){
            int j=sparse[i][2];
            transpose[t[j]][1]=sparse[i][2];
            transpose[t[j]][2]=sparse[i][1];
            transpose[t[j]][3]=sparse[i][3];
            t[j]++;
        }
        cout<<"The transpose is\n";
        for(int i=0;i<count+1;i++){
        for(int j=0;j<4;j++)
            cout<<transpose[i][j]<<"\t";
        cout<<endl;}
    return 0;
}
