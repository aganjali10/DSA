#include <iostream>
#include<math.h>
int n;

using namespace std;

void bubblesort(int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
        if(arr[i]>arr[j]){
            swap(arr[i],arr[j]);
        }
    }
}

void bubblesort(int arr[]){
    for(int i=0;i<n-1;i++){
	int s=0;
        for(int j=0;j<n-1-i;j++)
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
	    s++;
        }
	if(s==0)
	    break;
    }
}

void selectionsort(int arr[]){
    for(int i=0;i<n-1;i++){
        int small=i;
        for(int j=i+1;j<n;j++)
            if(arr[small]>arr[j])
            small=j;
        if(small!=i){
            swap(arr[i],arr[small]);
        }
    }
}

void insertionsort(int arr[]){
    for(int i=1;i<n;i++){
        int hole=i;
        int value=arr[i];
        while(hole>0&&arr[hole-1]>value){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
}

void merge(int *arr, int* left,int l,int* right,int r){
    int a=0,b=0,c=0;
    while(a<l&&b<r){
        if(left[a]<=right[b]){
            arr[c]=left[a];
            a++;
            c++;
        }
        else{
            arr[c]=right[b];
            b++;
            c++;
        }
    }
    while(a<l){
        arr[c]=left[a];
        a++;
        c++;
    }
    while(b<r){
        arr[c]=right[b];
        b++;
        c++;
    }
}

void mergesort(int *arr,int n){
    if(n<2)
        return;
    int mid=n/2;
    int* left=new int[mid];
    int* right=new int[n-mid];
    for(int i=0;i<mid;i++)
        left[i]=arr[i];
    for(int i=mid;i<n;i++)
        right[i-mid]=arr[i];
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(arr,left,mid,right,n-mid);
}

//Better space complexity O(n)
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2){
        arr[k++] = R[j++];
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l+(r-l)/2; //(l+r)/2
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int partition(int *arr,int start,int end){
    int pindex=start;
    int pivot=arr[end];
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            int temp=arr[i];
            arr[i]=arr[pindex];
            arr[pindex]=temp;
            pindex++;
        }
    }
    int temp=arr[end];
    arr[end]=arr[pindex];
    arr[pindex]=temp;
    return pindex;
}

void quicksort(int *arr,int start,int end){
    if(start<end){
        int pindex=partition(arr,start,end);
        quicksort(arr,start,pindex-1);
        quicksort(arr,pindex+1,end);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

#define MAX 100

int getmax(int* arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

void countsort(int* arr,int n){
    int i,temp[n],countx[10]={0};
    for(i=0;i<n;i++)
        countx[arr[i]]++;
    for(i=1;i<10;i++)
        countx[i]+=countx[i-1];
    for(i=0;i<n;i++){
        temp[countx[arr[i]]-1]=arr[i];
        countx[arr[i]]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=temp[i];
}

void countsortradix(int* arr,int n,int exp){
    int i,temp[n],countx[10]={0};
    for(i=0;i<n;i++)
        countx[(arr[i]/exp)%10]++;
    for(i=1;i<10;i++)
        countx[i]+=countx[i-1];
    for(i=n-1;i>=0;i--){
        temp[countx[(arr[i]/exp)%10]-1]=arr[i];
        countx[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=temp[i];
}

void radixsort(int* arr,int ){
    int max=getmax(arr,n);
    for(int exp=1;max/exp>0;exp*=10)
        countsortradix(arr,n,exp);
}

int main()
{
    cout << "Enter size of array\n";
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"1.Bubble Sort2.Selection Sort3.Insertion Sort4.Merge Sort5.Quick Sort6.Heap Sort7.Count Sort8.Radix Sort\n";
    int choice;
    cin>>choice;
    switch(choice){
    case 1:{bubblesort(arr);
    break;}
    case 2:{selectionsort(arr);
    break;}
    case 3:{insertionsort(arr);
    break;}
    case 4:{mergesort(arr,n);
    break;}
    case 5:{quicksort(arr,0,n-1);
    break;}
    case 6:{heapsort(arr,n);
    break;}
    case 7:{countsort(arr,n);
    break;}
    case 8:{radixsort(arr,n);
    break;}
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
