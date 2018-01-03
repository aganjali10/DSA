/*linear search
binary search
interpolation
bubble
insertion
selection
radix
heap
merge
quick()
strassen
prim imp
kruskal imp
dijkstra imp
bellmann imp
floyd?
knapsack greedy
knapsack dp imp
knapsack bnb doubt
dfs
lcs
matrix chain again
hashing
n queen
tsp doubt*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int linear_search(int* arr,int n,int x){
    for(int i=0;i<n;i++)
        if(arr[i]==x)
        return i;
    return -1;
} O(n) O(1)

int binary_search(int* arr,int l,int r,int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid]<x)
            l++;
        else
            r--;
    }
    return -1;
} O(logn) O(1)

int interpolation_search(int* arr,int l,int r,int x){
    while(l<=r&&(x>=arr[l]&&x<=arr[r])){
        int pos=l+(((double)(r-l))/(arr[r]-arr[l]))*(x-arr[l]);
        if(arr[pos]==x)
            return pos;
        if(arr[pos]<x)
            l++;
        else
            r--;
    }
    return -1;
} O(loglogn) O(1)

void bs(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int f=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                f++;
            }
        }
        if(!f)
            break;
    }
} O(n^2) O(1) yes(stable)

void ss(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int s=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[s])
                s=j;
        }
        swap(arr[i],arr[s]);
    }
} O(n^2) O(1) no

void is(int*arr,int n){
    for(int i=1;i<n;i++){
        int hole=i;
        int val=arr[i];
        while(hole>0&&arr[hole-1]>val){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=val;
    }
} O(n^2) O(1) O(n+d)/*d inversions*/ yes

void merge(int* a,int* b,int* c,int l,int m){
    int i=0,j=0,k=0;
    while(i<l&&j<m){
        if(a[i]<=b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<l){
            c[k++]=a[i++];
    }
    while(j<m){
            c[k++]=b[j++];
    }
}

void ms(int* arr,int n){
    if(n<2)
        return;
    int mid=n/2;
    int* a=new int[mid];
    int* b=new int[n-mid];
    for(int i=0;i<mid;i++){
        a[i]=arr[i];
        b[i]=arr[i+mid];
    }
    if(n%2)
        b[n-mid-1]=arr[n-1];
    ms(a,mid);
    ms(b,n-mid);
    merge(a,b,arr,mid,n-mid);
} O(nlogn) O(n) yes

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
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void heapify(int* arr,int i,int n){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&arr[largest]<arr[l])
        largest=l;
    if(r<n&&arr[largest]<arr[r])
        largest=r;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
}

void hs(int* arr,int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,i,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
} O(nlogn) O(1) no

void count(int* a,int n,int exp){
    int* c=new int[n];
    int b[10]={0};
    for(int i=0;i<n;i++)
        b[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        b[i]+=b[i-1];
    for(int i=n-1;i>=0;i--){
        c[b[(a[i]/exp)%10]-1]=a[i];
        b[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        a[i]=c[i];
}

void rs(int* arr,int n){
    int max=*max_element(arr,arr+n);
    for(int exp=1;max/exp>0;exp*=10)
        count(arr,n,exp);
} d no of digits
    n no of elements
    b base
    k largest no
    k<=n^c
O(d(n+b)) = O((log(baseb)k)(n+b)) = O(nlog(baseb)n) = O(n)(if b=n)
    O(n+b) yes

int partition(int* arr,int l,int r){
    int pivot=arr[r];
    int s=l;
    for(int i=l;i<r;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[s]);
            s++;
        }
    }
    swap(arr[s],arr[r]);
    return s;
}

void qs(int* arr,int l,int r){
    if(l>=r)
        return;
    int p=partition(arr,l,r);
    qs(arr,l,p-1);
    qs(arr,p+1,r);
} O(nlogn) O(n) no



#define ipair pair < int , int >
vector < ipair > adj[10];

#define inf 10000

void prim(int src,int n){
    priority_queue< ipair , vector < ipair > , greater < ipair > > pq;
    vector < bool > inmst(n,false);
    vector <int> parent(n,-1);
    vector <int> key(n,inf);
    key[src]=0;
    pq.push(make_pair(0,src));
    int wt=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(!inmst[u])
            wt+=key[u];
        inmst[u]=true;
        vector < ipair > :: iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){ /*total O(E)*/
            int v=it->first;
            int w=it->second;
            if(!inmst[v]&&key[v]>w){
                key[v]=w;
                parent[v]=u;
                pq.push(make_pair(key[v],v)); /*O(logv)*/
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i!=src)
            cout<<parent[i]<<'-'<<i<<'\n';
    }
    cout<<wt;
}  O(elogv) O(v)

vector <int> rnk;
vector <int> parent;

int find(int u){
    if(parent[u]!=u)
        parent[u]=find(parent[u]);
    return parent[u];
}

void merge(int u,int v){
    u=find(u);
    v=find(v);
    if(rnk[u]<rnk[v])
        parent[u]=v;
    else
        parent[v]=u;
    if(rnk[u]==rnk[v])
        rnk[u]++;
}

vector < pair < int , ipair > > edges;

void kruskal(int src,int n){
    vector < pair < int , ipair > > :: iterator it;
    int wt=0;
    for(it=edges.begin();it!=edges.end();it++){
        int u=it->second.first;
        int v=it->second.second;
        int w=it->first;
        int set_u=find(u);
        int set_v=find(v);
        if(set_u!=set_v){
            cout<<u<<'-'<<v<<'\n';
            wt+=w;
            merge(u,v);
        }
    }
    cout<<wt;
} O(ElogV) O(V)

void dijkstra(int src,int n){
    priority_queue < ipair, vector < ipair > , greater < ipair > > pq;
    vector < int > dist(n,inf);
    dist[src]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        vector < ipair > :: iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            int v=it->first;
            int w=it->second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
} O(ElogV) O(V)

vector < int > bellmanford(int src,int n){
    vector < int > distance (n,inf);
    distance[src]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<edges.size();j++){
            int u=edges[j].second.first;
            int v=edges[j].second.second;
            int w=edges[j].first;
            if(distance[v]>distance[u]+w)
                distance[v]=distance[u]+w;
        }
    }
    for(int j=0;j<edges.size();j++){
            int u=edges[j].second.first;
            int v=edges[j].second.second;
            int w=edges[j].first;
            if(distance[v]>distance[u]+w)
                return vector <int> ();
        }
        return distance;
} O(VE)

void floyd(int n,int** arr){
    int** dist=new int*[n];
    for(int i=0;i<n;i++)
        dist[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        dist[i][j]=arr[i][j];
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(dist[i][j]==inf)
            cout<<"inf ";
            else
                cout<<dist[i][j]<<' ';
        cout<<'\n';
    }
} O(V^3)

/*ab  ef
cd  gh
a(f-h)
h(a+b)
e(c+d)
d(g-e)
(a+d)(e+h)
(b-d)(g+h)
(a-c)(e+f)*/

void sum(int** a,int** b,int** c,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        c[i][j]=a[i][j]+b[i][j];
}

void sub(int** a,int** b,int** c,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        c[i][j]=a[i][j]-b[i][j];
}

void strassen(int** a,int** b,int** c,int n){
    if(n<2){
        c[0][0]=a[0][0]*b[0][0];
        return;
    }
    int** aux1=new int*[n/2];
    int** aux2=new int*[n/2];
    int** m1=new int*[n/2];
    int** m2=new int*[n/2];
    int** m3=new int*[n/2];
    int** m4=new int*[n/2];
    int** m5=new int*[n/2];
    int** m6=new int*[n/2];
    int** m7=new int*[n/2];
    int** a11=new int*[n/2];
    int** a12=new int*[n/2];
    int** a21=new int*[n/2];
    int** a22=new int*[n/2];
    int** b11=new int*[n/2];
    int** b12=new int*[n/2];
    int** b21=new int*[n/2];
    int** b22=new int*[n/2];
    int** c11=new int*[n/2];
    int** c12=new int*[n/2];
    int** c21=new int*[n/2];
    int** c22=new int*[n/2];
    for(int i=0;i<n/2;i++){
        aux1[i]=new int[n/2];
        aux2[i]=new int[n/2];
        m1[i]=new int[n/2];
        m2[i]=new int[n/2];
        m3[i]=new int[n/2];
        m4[i]=new int[n/2];
        m5[i]=new int[n/2];
        m6[i]=new int[n/2];
        m7[i]=new int[n/2];
        a11[i]=new int[n/2];
        a12[i]=new int[n/2];
        a21[i]=new int[n/2];
        a22[i]=new int[n/2];
        b11[i]=new int[n/2];
        b12[i]=new int[n/2];
        b21[i]=new int[n/2];
        b22[i]=new int[n/2];
        c11[i]=new int[n/2];
        c12[i]=new int[n/2];
        c21[i]=new int[n/2];
        c22[i]=new int[n/2];
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            a11[i][j]=a[i][j];
            a12[i][j]=a[i][j+n/2];
            a21[i][j]=a[i+n/2][j];
            a22[i][j]=a[i+n/2][j+n/2];
            b11[i][j]=b[i][j];
            b12[i][j]=b[i][j+n/2];
            b21[i][j]=b[i+n/2][j];
            b22[i][j]=b[i+n/2][j+n/2];
        }
    }
        /*ab  ef
        cd  gh
        a(f-h) a11(b12-b22)
        h(a+b)  b22(a11+a12)
        e(c+d)  b11(a21+a22)
        d(g-e)  a22(b21-b11)
        (a+d)(e+h)  (a11+a22)(b11+b22)
        (b-d)(g+h)  (a12-a22)(b21+b22)
        (a-c)(e+f) (a11-a21)(b11+b12)*/
        sub(b12,b22,aux1,n/2);
        strassen(a11,aux1,m1,n/2);
        sum(a11,a12,aux1,n/2);
        strassen(b22,aux1,m2,n/2);
        sum(a21,a22,aux1,n/2);
        strassen(b11,aux1,m3,n/2);
        sub(b21,b11,aux1,n/2);
        strassen(a22,aux1,m4,n/2);
        sum(a11,a22,aux1,n/2);
        sum(b11,b22,aux2,n/2);
        strassen(aux1,aux2,m5,n/2);
        sub(a12,a22,aux1,n/2);
        sum(b21,b22,aux2,n/2);
        strassen(aux1,aux2,m6,n/2);
        sub(a11,a21,aux1,n/2);
        sum(b11,b12,aux2,n/2);
        strassen(aux1,aux2,m7,n/2);
        sum(m4,m5,aux1,n/2);
        sub(m6,m2,aux2,n/2);
        sum(aux1,aux2,c11,n/2);
        sum(m1,m2,c12,n/2);
        sum(m3,m4,c21,n/2);
        sub(m1,m3,aux1,n/2);
        sub(m5,m7,aux2,n/2);
        sum(aux1,aux2,c22,n/2);
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                c[i][j]=c11[i][j];
                c[i][j+n/2]=c12[i][j];
                c[i+n/2][j]=c21[i][j];
                c[i+n/2][j+n/2]=c22[i][j];
            }
        }
} O(n^log7)

struct ele{
    int v,w;
};

bool compare(ele a,ele b){
    return ((double)(a.w)/(double)(a.v))<((double)(b.w)/(double)(b.v));
}

void ksgreedy(ele* arr,int n,int w){
    sort(arr,arr+n,compare);
    int cw=0;
    int i=0;
    int val=0;
    while(cw<w){
        int r=w-cw;
        if(r>=arr[i].w){
            val+=arr[i].v;
            cw+=arr[i].w;
        }
        else{
            val+=((double)(r)/(double)(arr[i].w))*arr[i].v;
            break;
        }
        i++;
    }
    cout<<val;
} O(nlogn)

int ksdp(ele* arr,int n,int w){
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=new int[w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(arr[i].w<=j)
                dp[i][j]=max(arr[i-1].v+dp[i-1][j-arr[i-1].w],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
} O(nw)

void lcs(string a,string b,int m,int n){
    int** dp=new int*[m+1];
    for(int i=0;i<=m;i++)
        dp[i]=new int[n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int l=dp[m][n];
    char ans[l+1];
    ans[l]='\0';
    int i=m,j=n;
    while(i>0&&j>0){
        if(a[i-1]==b[j-1])
        {
            ans[l-1]=a[i-1];
            i--;
            l--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<ans<<'\n';
    cout<<dp[m][n];
} o(mn)

void print(int** arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<'\n';
    }
}

bool issafe(int** arr,int row,int col,int n){
    for(int i=0;i<col;i++)
        if(arr[row][i])
        return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(arr[i][j])
            return false;
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
        if(arr[i][j])
            return false;
    return true;
}

bool nqutil(int** arr,int col,int n){
    if(col>=n)
        return true;
    for(int row=0;row<n;row++){
        if(issafe(arr,row,col,n)){
            arr[row][col]=1;
            if(nqutil(arr,col+1,n))
                return true;
            arr[row][col]=0;
        }
    }
    return false;
}

void nq(int n){
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    if(nqutil(arr,0,n))
        print(arr,n);
    else
        cout<<"no";
}

matrixChain(int n,int* order){
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=new int[n+1];
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int size=2;size<=n;size++){
        for(int i=1;i<=n-size+1;i++){
            int j=i+size-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int temp=dp[i][k]+dp[k+1][j]+order[i-1]*order[k]*order[j];
                if(temp<dp[i][j])
                    dp[i][j]=temp;
            }
        }
    }
    return dp[1][n];
} O(n^3)

vector <bool> vis(10,false);

vector <int> adj1[10];

void dfsutil(int u){
    vis[u]=true;
    cout<<u;
    for(int i=0;i<adj1[u].size();i++){
        if(vis[adj1[u][i]]==false)
        dfsutil(adj1[u][i]);
    }
}

void dfs(int n){
    for(int i=0;i<n;i++)
        if(!vis[i])
        dfsutil(i);
} O(n)

struct node{
    string key,value;
    node* next;
};

#define MAX_SIZE 5

node* hash_table[MAX_SIZE];

void initialize(){
    for(int i=0;i<MAX_SIZE;i++){
        hash_table[i]=new node;
        hash_table[i]->key="Empty";
        hash_table[i]->next=NULL;
    }
}

int hash_function(string x){
    int n=x.length();
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=x[i];
    return (sum%MAX_SIZE);
}

void insert_key(string key,string value){
    int index=hash_function(key);
    if(hash_table[index]->key=="Empty"){
        hash_table[index]->key=key;
        hash_table[index]->value=value;
        return;
    }
    node* newnode=new node;
    newnode->next=NULL;
    newnode->key=key;
    newnode->value=value;
    node* temp=hash_table[index];
    while(temp->next)
        temp=temp->next;
    temp->next=newnode;
}

void delete_key(string key){
    int index=hash_function(key);
    if(hash_table[index]->key==key){
        if(hash_table[index]->next==NULL)
            hash_table[index]->key="Empty";
        else
            hash_table[index]=hash_table[index]->next;
        return;
    }
    node* temp=hash_table[index];
    node* prev=temp->next;
    while(prev->key!=key){
        temp=temp->next;
        prev=prev->next;
    }
    temp->next=prev->next;
}

void display(){
    for(int i=0;i<MAX_SIZE;i++){
        node* temp=hash_table[i];
        if(hash_table[i]->key=="Empty"){
            cout<<"Empty\n-----\n";
            continue;
        }
        while(temp){
            cout<<temp->key<<' '<<temp->value<<'\n';
            temp=temp->next;
        }
        cout<<"-----\n";
    }
} insertion O(n)
    deletion O(n)
    display O(n)

const int N = 4;
int final_path[N+1];
bool visited[N];
int final_res = INT_MAX;

void copyToFinal(int curr_path[]){
    for (int i=0; i<N; i++)
        final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}

 int firstMin(int adj[N][N], int i){
    int min = INT_MAX;
    for (int k=0; k<N; k++)
        if (adj[i][k]<min && i != k)
            min = adj[i][k];
    return min;
}

 int secondMin(int adj[N][N], int i){
    int first = INT_MAX, second = INT_MAX;
    for (int j=0; j<N; j++){
        if (i == j)
            continue;
        if (adj[i][j] <= first){
            second = first;
            first = adj[i][j];}
        else if (adj[i][j] <= second &&
                 adj[i][j] != first)
            second = adj[i][j];}
    return second;}

 void TSPRec(int adj[N][N], int curr_bound, int curr_weight, int level, int curr_path[]){
    if (level==N){
     if (adj[curr_path[level-1]][curr_path[0]] != 0){
            int curr_res = curr_weight +
                    adj[curr_path[level-1]][curr_path[0]];
            if (curr_res < final_res){
                copyToFinal(curr_path);
                final_res = curr_res;}}
        return;
    }
    for (int i=0; i<N; i++){
        if (adj[curr_path[level-1]][i] != 0 && visited[i] == false){
            int temp = curr_bound;
            curr_weight += adj[curr_path[level-1]][i];
            if (level==1)
              curr_bound -= ((firstMin(adj, curr_path[level-1]) + firstMin(adj, i))/2);
            else
              curr_bound -= ((secondMin(adj, curr_path[level-1]) + firstMin(adj, i))/2);
            if (curr_bound + curr_weight < final_res){
                curr_path[level] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_weight, level+1,
                       curr_path);}
            curr_weight -= adj[curr_path[level-1]][i];
            curr_bound = temp;
            memset(visited, false, sizeof(visited));
            for (int j=0; j<=level-1; j++)
                visited[curr_path[j]] = true;
                }
    }
}

void TSP(int adj[N][N]){
    int curr_path[N+1];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));
    for (int i=0; i<N; i++)
        curr_bound += (firstMin(adj, i) +
                       secondMin(adj, i));
    curr_bound = (curr_bound&1)? curr_bound/2 + 1 :
                                 curr_bound/2;

    visited[0] = true;
    curr_path[0] = 0;
    TSPRec(adj, curr_bound, 0, 1, curr_path);
} O((n^2)*(2^n))dp
O(n!) naive

int main()
{
    int adj[N][N] ;
    cout<<"Enter the undirected graph of order 4\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>adj[i][j];}}
    TSP(adj);
    cout<<"Minimum cost : "<<final_res<<'\n';
    cout<<"Path Taken : ";
    for (int i=0; i<=N; i++)
        cout<<final_path[i]<<" ";
    return 0;
}



/*OUTPUT
Enter the undirected graph of order 4
1 2 3 4
2 5 6 7
3 6 7 8
4 7 8 9
Minimum cost : 20
Path Taken : 0 1 2 3 0*/
