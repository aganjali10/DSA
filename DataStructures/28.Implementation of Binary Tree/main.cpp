#include <iostream>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;

#define MAX 100

struct node{
    int data;
    node* left;
    node* right;
};

node* root=NULL;

queue<node*>q;

node* getnewnode(int info){
    node* newnode= new node;
    newnode->data=info;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}

void create(){
        cout<<"Enter data\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        root=newnode;
        q.push(root);
        cout<<"Want to add more nodes?(y/n)\n";
        char c;
        cin>>c;
        while(c=='y'){
        cout<<"Enter data\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        node* temp=q.front();
        if(temp->left==NULL)
            temp->left=newnode;
        else if(temp->right==NULL)
            temp->right=newnode;
        if(temp->left!=NULL&&temp->right!=NULL)
            q.pop();
        q.push(newnode);
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
    }
}

/*Stupid Method
void levelorder(){
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* current=q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL)
            q.push(current->left);
        if(current->right!=NULL)
            q.push(current->right);
        q.pop();
    }
} */

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void levelorder(){
	if (root == NULL)  return;
    queue<node *> q;
    q.push(root);
 
    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
        while (nodeCount > 0)
        {
            node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout <<endl;
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 

void reverseLevelOrder(node* root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);
 
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
 
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
 
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
 
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}


void reverseLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printGivenLevel(root, i);
}


void preorder(node* p){
    if(p==NULL) return;
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}

void inorder(node* p){
    if(p==NULL) return;
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
}

void postorder(node* p){
    if(p==NULL) return;
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
}

int calc_height(node* p){
    if(p==NULL)
        return -1;
    return max(calc_height(p->left),calc_height(p->right))+1;
}

int top=-1;

node* stack1[MAX];

void push(node* value){
    if(top==MAX-1){
        cout<<"Stack full\n";
        return;
    }
    top++;
    stack1[top]=value;
}

node* pop(){
    if(top==-1){
        return NULL;
    }
    node* value=stack1[top];
    top--;
    return value;
}

void preorderi(node* p){
    while(1){
        while(p!=NULL){
            cout<<p->data<<" ";
            if(p->right!=NULL)
                push(p->right);
            p=p->left;
        }
        p=pop();
        if(p==NULL)
            return;
    }
}

void inorderi(node* p){
    while(1){
        while(p!=NULL){
          push(p);
          p=p->left;
        }
        p=pop();
        if(p==NULL)
            return;
        cout<<p->data<<" ";
        p=p->right;
    }
}

void postorderi(node* p)
{
    if (p == NULL)
        return;
    stack<node*>s1;
    stack<node*>s2;
    s1.push(p);
    node* node;
    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout<<node->data<<" ";
    }
}

void zigzag(node* p){
    if(p==NULL) return;
    stack<node*>s1;
    stack<node*>s2;
    s1.push(p);
    while(!s1.empty()||!s2.empty()){
        while(!s1.empty()){
            node* temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                s2.push(temp->left);
                if(temp->right!=NULL)
                    s2.push(temp->right);
        }
        while(!s2.empty()){
        node* temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
            s1.push(temp->right);
        if(temp->left!=NULL)
            s1.push(temp->left);
        }
    }
}

int calc_nonleaf(node* p){
    if(p==NULL)
        return 0;
    else if(p->left!=NULL||p->right!=NULL)
        return calc_nonleaf(p->left)+calc_nonleaf(p->right)+1;
    else
        return 0;
}

int calc_nonleafi(node* p){
    if(p==NULL)
        return 0;
    queue<node*>q1;
    q1.push(p);
    int count=0;
    while(!q1.empty()){
        node* temp=q1.front();
        if(temp->left!=NULL)
            q1.push(temp->left);
        if(temp->right!=NULL)
            q1.push(temp->right);
        count++;
        if(temp->left==NULL&&temp->right==NULL)
            count--;
        q1.pop();
    }
    return count;
}

int calc_leaf(node* p){
    if(p==NULL)
        return 0;
    else if(p->left==NULL&&p->right==NULL)
        return 1;
    else
        return calc_leaf(p->left)+calc_leaf(p->right);
}

int count_nodes(node* p){
	if(!p)
           return 0;
	return 1+count_nodes(p->left)+count_nodes(p->right);
}

int calc_min(node* p){
    int m,l,r;
    if(p!=NULL){
        m=p->data;
        if(p->left!=NULL){
            l=calc_min(p->left);
            if(m>l)
                m=l;
        }
        if(p->right!=NULL){
            r=calc_min(p->right);
            if(m>r)
                m=r;
        }
        return m;
    }
    return -1;
}

int calc_max(node* p){
    int m,l,r;
    if(p!=NULL){
        m=p->data;
        if(p->left!=NULL){
            l=calc_max(p->left);
            if(m<l)
                m=l;
        }
        if(p->right!=NULL){
            r=calc_max(p->right);
            if(m<r)
                m=r;
        }
        return m;
    }
    return 1000;
}

void print_levelorder(){
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    int var=0;
    int level=0;
    while(!q.empty()){
        node* temp=q.front();
        cout<<temp->data<<" ";
        var++;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        if(pow(2,level)==var){
            var=0;
            cout<<endl;
            level++;
        }
        q.pop();
    }
}

node* mirror_tree(node* root){
    if(root==NULL)
        return NULL;
            node* temp=root->left;
            root->left=root->right;
            root->right=temp;
       root->left=mirror_tree(root->left);
    root->right=mirror_tree(root->right);
    return root;

}

int checkbst(node* root){
    if(root==NULL)
        return 1;
    if(root->left!=NULL&&calc_max(root->left)>root->data)
        return 0;
    if(root->right!=NULL&&calc_min(root->right)<root->data)
        return 0;
    if(!checkbst(root->left)||!checkbst(root->right))
        return 0;
    return 1;
}

/* Helper function for getLevel().  It returns level of the data if data is
   present in tree, otherwise returns 0.*/
int getLevelUtil(node *node, int data, int level)
{
    if (node == NULL)
        return 0;
 
    if (node->data == data)
        return level;
 
    int downlevel = getLevelUtil(node->left, data, level+1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(node->right, data, level+1);
    return downlevel;
}
 
/* Returns level of given data value */
int getLevel(node *node, int data)
{
    return getLevelUtil(node,data,1);
}

/* To test if a binary tree is perfect
   or not. Basically check for two things :
   Method 1:1) All leaves are at same level
   2) All internal nodes have two children 
   Method 2:Cal no of nodes and height
   If number of nodes=(2^height-1)
   then perfect else not */
//Tree Symmetric or not
bool isMirror(struct Node *root1, struct Node *root2)
{
    // If both trees are emptu, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;
 
    // For two trees to be mirror images, the following three
    // conditions must be true
    // 1 - Their root node's key must be same
    // 2 - left subtree of left tree and right subtree
    //      of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree
    //      of right tree have to be mirror images
    if (root1 && root2 && root1->key == root2->key)
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);
 
    // if neither of above conditions is true then root1
    // and root2 are not mirror images
    return false;
}
 
// Returns true if a tree is symmetric i.e. mirror image of itself
bool isSymmetric(struct Node* root)
{
    // Check if tre is mirror of itself
    return isMirror(root, root);
}

bool isBalanced(Node *root)
{
   int lh; 
   int rh;
   if(root == NULL)
    return 1; 
   lh = height(root->left);
   rh = height(root->right);
   if( abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
     return 1;
   return 0;
}

bool isCompleteUtil(Node* root,int index,int number_nodes){
    if(!root)
    return true;
    if(index>=number_nodes)
    return false;
    return(isCompleteUtil(root->left,2*index+1,number_nodes)&&isCompleteUtil(root->right,2*index+2,number_nodes));
}

bool isHeapUtil(Node* root){
    if((!(root->left))&&(!(root->right)))
    return true;
    if((!(root->right)))
    return(root->left->data<root->data);
    else{
        if(root->left->data<root->data&&root->right->data<root->data)
        return isHeapUtil(root->left)&&isHeapUtil(root->right);
        else
        return false;
    }
}

/*Check if maxheap or not */
bool isHeap(Node * tree)
{
 int count=count_nodes(tree);
 return (isCompleteUtil(tree,0,count)&&isHeapUtil(tree));
}

//Find mirror of a given node. If doesn't exist print -1



using namespace std;

int main()
{
    create();
    levelorder(); cout<<endl;
    node* p=root;
    preorder(p); cout<<endl;
    inorder(p); cout<<endl;
    postorder(p); cout<<endl;
    int height=calc_height(p);
    cout<<"height: "<<height<<endl;
    preorderi(p); cout<<endl;
    inorderi(p); cout<<endl;
    postorderi(p); cout<<endl;
    zigzag(p); cout<<endl;
    int nonleaf=calc_nonleaf(p);
    cout<<"nonleaf: "<<nonleaf<<endl;
    nonleaf=calc_nonleafi(p);
    cout<<"nonleaf: "<<nonleaf<<endl;
    int leaf=calc_leaf(p);
    cout<<"leaf: "<<leaf<<endl;
    int min=calc_min(p);
    cout<<"min: "<<min<<endl;
    int max=calc_max(p);
    cout<<"max: "<<max<<endl;
    print_levelorder(); cout<<endl;
    root=mirror_tree(root);
    print_levelorder(); cout<<endl;
    if(checkbst(root))
        cout<<"YES";
    else
        cout<<"NO";
    int data;
    cin>>data;
    cout<<getlevel(root,data);
    return 0;
}
