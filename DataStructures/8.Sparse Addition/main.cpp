#include <iostream>

using namespace std;

int m,n,p,q;

int main()
{
    cout<<"Enter number of rows and columns of the first matrix\n";
    cin>>m>>n;
    int** arr1=new int*[m];
    for(int i=0;i<m;i++)
        arr1[i]=new int[n];
        int count1=0;
    cout<<"Enter the elements\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
            if(arr1[i][j]!=0)
                count1++;
        }
    }
    int** sparse1=new int*[count1+1];
    for(int i=0;i<count1+1;i++)
        sparse1[i]=new int[4];
    for(int i=0;i<count1+1;i++)
        sparse1[i][0]=i;
    sparse1[0][1]=m;
    sparse1[0][2]=n;
    sparse1[0][3]=count1;
    int ptr=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr1[i][j]!=0){
                sparse1[ptr][1]=i;
                sparse1[ptr][2]=j;
                sparse1[ptr][3]=arr1[i][j];
                ptr++;
            }
        }
    }
    cout<<"The sparse matrix is\n";
    for(int i=0;i<count1+1;i++){
        for(int j=0;j<4;j++)
            cout<<sparse1[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"Enter number of rows and columns of the second matrix\n";
    cin>>p>>q;
    int** arr2=new int*[p];
    for(int i=0;i<p;i++)
        arr2[i]=new int[q];
        int count2=0;
    cout<<"Enter the elements\n";
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>arr2[i][j];
            if(arr2[i][j]!=0)
                count2++;
        }
    }
    int** sparse2=new int*[count2+1];
    for(int i=0;i<count2+1;i++)
        sparse2[i]=new int[4];
    for(int i=0;i<count2+1;i++)
        sparse2[i][0]=i;
    sparse2[0][1]=p;
    sparse2[0][2]=q;
    sparse2[0][3]=count2;
    ptr=1;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(arr2[i][j]!=0){
                sparse2[ptr][1]=i;
                sparse2[ptr][2]=j;
                sparse2[ptr][3]=arr2[i][j];
                ptr++;
            }
        }
    }
    cout<<"The sparse matrix is\n";
    for(int i=0;i<count2+1;i++){
        for(int j=0;j<4;j++)
            cout<<sparse2[i][j]<<"\t";
        cout<<endl;
    }
    if(m!=p&&n!=q){
        cout<<"NOT POSSIBLE";
        return 0;
    }
    int** sparse3=new int*[count1+count2+1];
    for(int i=0;i<count1+count2+1;i++)
        sparse3[i]=new int[4];
    for(int i=0;i<count1+count2+1;i++)
        sparse3[i][0]=i;
    sparse3[0][1]=m;
    sparse3[0][2]=n;
    int a=1;
    int b=1;
    int c=1;
    while(a<count1+1&&b<count2+1){
        if(sparse1[a][1]==sparse2[b][1]){
            if(sparse1[a][2]==sparse2[b][2]){
                sparse3[c][1]=sparse1[a][1];
                sparse3[c][2]=sparse1[a][2];
                sparse3[c][3]=sparse1[a][3]+sparse2[b][3];
                a++; b++; c++;
            }
            else if(sparse1[a][2]<sparse2[b][2]){
                sparse3[c][1]=sparse1[a][1];
                sparse3[c][2]=sparse1[a][2];
                sparse3[c][3]=sparse1[a][3];
                a++;
                c++;
            }
            else{
                sparse3[c][1]=sparse2[b][1];
                sparse3[c][2]=sparse2[b][2];
                sparse3[c][3]=sparse2[b][3];
                b++; c++;
            }
        }
        else if(sparse1[a][1]<sparse2[b][1]){
            sparse3[c][1]=sparse1[a][1];
                sparse3[c][2]=sparse1[a][2];
                sparse3[c][3]=sparse1[a][3];
                a++;
                c++;
        }
        else{
            sparse3[c][1]=sparse2[b][1];
                sparse3[c][2]=sparse2[b][2];
                sparse3[c][3]=sparse2[b][3];
                b++; c++;
        }
    }
    while(a<count1+1){
        sparse3[c][1]=sparse1[a][1];
                sparse3[c][2]=sparse1[a][2];
                sparse3[c][3]=sparse1[a][3];
                a++;
                c++;
    }
    while(b<count2+1){
        sparse3[c][1]=sparse2[b][1];
                sparse3[c][2]=sparse2[b][2];
                sparse3[c][3]=sparse2[b][3];
                b++; c++;
    }
    cout<<"The sum is\n";
    sparse3[0][3]=c-1;
    for(int i=0;i<c;i++){
        for(int j=0;j<4;j++)
            cout<<sparse3[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
