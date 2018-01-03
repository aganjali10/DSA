#include <iostream>
#include<queue>


using namespace std;

struct node{
    int data;
    node* right;
    node* left;
};

node* getnewnode(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int searchfunc(int inorder[],int ele,int start,int ende)
{
        for(int i=start;i<=ende;++i)
        {
            if(inorder[i]==ele)
                return i;
        }
        return -1;
}
node* construct(int inorder[],int preorder[],int start,int ende)
{
    if(start>ende)
        return NULL;
    static int pi=0;
    int data=preorder[pi++];
    int ii=searchfunc(inorder,data,start,ende);
    node* root=getnewnode(data);
    if(start==ende)
        return root;
    root->left=construct(inorder,preorder,start,ii-1);
    root->right=construct(inorder,preorder,ii+1,ende);
    return root;

}
void levelorder(node* root){
  if(root==NULL)
        return;
  queue<node*>q;
  q.push(root);
  while(!q.empty())
  {
      node * temp=q.front();
      cout<<temp->data<<" ";
      if(temp->left!=NULL)
      q.push(temp->left);
      if(temp->right!=NULL)
      q.push(temp->right);
      q.pop();
  }
}

int main()
{
    int in[]   = {8, 4, 9, 2, 5, 1, 6, 3, 7};
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    node* root1=construct(in,pre,0,8);
    levelorder(root1);
    return 0;
}
