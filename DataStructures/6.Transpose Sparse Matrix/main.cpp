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
        int row=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<count+1;j++){
                if(sparse[j][2]==i){
                        transpose[row][1]=sparse[j][2];
                        transpose[row][2]=sparse[j][1];
                        transpose[row][3]=sparse[j][3];
                    row++;
                }
            }
        }
        cout<<"The transpose is\n";
        for(int i=0;i<count+1;i++){
        for(int j=0;j<4;j++)
            cout<<transpose[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
