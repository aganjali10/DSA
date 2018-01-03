#include <iostream>
#include<queue>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* root1=NULL;
node* root2=NULL;

node* getnewnode(int info){
    node* newnode= new node;
    newnode->data=info;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}

void create1(){
    queue<node*>q;
        cout<<"Enter data\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        root1=newnode;
        q.push(root1);
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

void create2(){
    queue<node*>q;
        cout<<"Enter data\n";
        int info;
        cin>>info;
        node* newnode=getnewnode(info);
        root2=newnode;
        q.push(root2);
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
/*
  int *arr=new int[100];
  int *brr=new int[100];
  int a=0,b=0;
  void levelorder(node* root)
{
  if(root==NULL)return;
  queue<node*>Q;
  Q.push(root);
  while(!Q.empty()){
      node* current=Q.front();
      arr[a++]=current->data;
      if(current->left!=NULL)
      Q.push(current->left);
      if(current->right!=NULL)
      Q.push(current->right);
      Q.pop();
}
}
  void levelorder2(node* root)
{
  if(root==NULL)return;
  queue<node*>Q;
  Q.push(root);
  while(!Q.empty()){
      node* current=Q.front();
      brr[b++]=current->data;
      if(current->left!=NULL)
      Q.push(current->left);
      if(current->right!=NULL)
      Q.push(current->right);
      Q.pop();
  }
}
int CompareBinaryTrees(node* A,node* B)
{
  levelorder(A);
  levelorder2(B);
  if(a!=b)
  return 0;
  int count=0;
  for(int i=0;i<a;i++)
  if(arr[i]==brr[i])
  count++;
  if(count==a)
  return 1;
  return 0;
} */

int identicalTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a==NULL && b==NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
     
    /* 3. one empty, one not -> false */
    return 0;
} 

bool areIdenticali(Node *root1, Node *root2)
{
    // Return true if both trees are empty
    if (!root1  && !root2) return true;
 
    // Return false if one is empty and other is not
    if (!root1 || !root2)  return false;
 
    // Create an empty queues for simultaneous traversals 
    queue<Node *> q1, q2;
 
    // Enqueue Roots of trees in respective queues
    q1.push(root1);
    q2.push(root2);
 
    while (!q1.empty() && !q2.empty())
    {
        // Get front nodes and compare them
        Node *n1 = q1.front();
        Node *n2 = q2.front();
 
        if (n1->data != n2->data)
           return false;
 
        // Remove front nodes from queues
        q1.pop(), q2.pop();
 
        /* Enqueue left children of both nodes */
        if (n1->left && n2->left)
        {
            q1.push(n1->left);
            q2.push(n2->left);
        }
 
        // If one left child is empty and other is not
        else if (n1->left || n2->left)
            return false;
 
        // Right child code (Similar to left child code)
        if (n1->right && n2->right)
        {
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if (n1->right || n2->right)
            return false;
    }
 
    return true;
}

//Structures are exactly same
int isomorphic(node* S,node* T){
    if(S==NULL&&T==NULL)
        return 1;
        if((S!=NULL&&T==NULL)||(S==NULL&&T!=NULL))
            return 0;
        if((S->left==NULL&&T->left!=NULL)||(S->left!=NULL&&T->left==NULL)||(S->right==NULL&&T->right!=NULL)||(S->right!=NULL&&T->right==NULL))
            return 0;
        else{
            int one=isomorphic(S->left,T->left);
            if(one);
            one=isomorphic(S->right,T->right);
            return one;
        }
}

/*Write a function to detect if two trees are isomorphic. 
Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. 
Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.*/
bool isIsomorphic(node* n1, node *n2)
{
 // Both roots are NULL, trees isomorphic by definition
 if (n1 == NULL && n2 == NULL)
    return true;
 
 // Exactly one of the n1 and n2 is NULL, trees not isomorphic
 if (n1 == NULL || n2 == NULL)
    return false;
 
 if (n1->data != n2->data)
    return false;
 
 // There are two possible cases for n1 and n2 to be isomorphic
 // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
 // Both of these subtrees have to be isomorphic, hence the &&
 // Case 2: The subtrees rooted at these nodes have been "Flipped"
 return
 (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))||
 (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
}

int main()
{
    create1();
    create2();
    if(CompareBinaryTrees(root1,root2))
        cout<<"YES";
    else
        cout<<"NO";
        cout<<endl;
        if(isomorphic)
            cout<<"YES";
        else
            cout<<"NO";
    return 0;
}
