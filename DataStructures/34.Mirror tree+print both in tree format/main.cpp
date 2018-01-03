#include <iostream>
#include<queue>
#include<math.h>

using namespace std;

struct node{
    int data;
    node *left,*right;
};

node* root=NULL;

node* getnewnode(int info){
    node* newnode=new node;
    newnode->data=info;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void create(){
    queue<node*>q;
    cout<<"Enter data\n";
    int info;
    cin>>info;
    root=getnewnode(info);
    cout<<"Want to add more nodes?(y/n)\n";
    char c;
    cin>>c;
    q.push(root);
    while(c=='y'){
        cout<<"Enter data\n";
        cin>>info;
        node* newnode=getnewnode(info);
        if(q.front()->left==NULL)
            q.front()->left=newnode;
        else
            q.front()->right=newnode;
        if(q.front()->left!=NULL&&q.front()->right!=NULL)
            q.pop();
        q.push(newnode);
        cout<<"Want to add more nodes?(y/n)\n";
        cin>>c;
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

int calc_leaf(node* p){
    if(p==NULL)
        return 0;
    else if(p->left==NULL&&p->right==NULL)
        return 1;
    else
        return calc_leaf(p->left)+calc_leaf(p->right);
}

int calc_nodes(){
    return calc_nonleaf(root)+calc_leaf(root);
}

void print_levelorder(){
    int h=3;
    queue<node*>q;
    int var=0;
    int level=0;
    q.push(root);
    while(!q.empty()){
        if(var==0)
            for(int i=1;i<=pow(2,h-level)-1;i++)
                cout<<"\t";
            else
                for(int i=1;i<=pow(2,h+1-level);i++)
                cout<<"\t";
        cout<<q.front()->data;
        var++;
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        q.pop();
        if(pow(2,level)==var){
            var=0;
            cout<<endl<<endl;
            level++;
        }
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
}

void print_levelordermirror(){
    int h=3;
    int nodes=calc_nodes();
    queue<node*>q;
    int var=0;
    int level=0;
    q.push(root);
    while(!q.empty()){
            if(level==h&&var==0){
                for(int i=1;i<=2*(pow(2,h+1)-1-nodes);i++)
                    cout<<"\t";
            }
        if(var==0)
            for(int i=1;i<=pow(2,h-level)-1;i++)
                cout<<"\t";
            else
                for(int i=1;i<=pow(2,h+1-level);i++)
                cout<<"\t";
        cout<<q.front()->data;
        var++;
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        q.pop();
        if(pow(2,level)==var){
            var=0;
            cout<<endl<<endl;
            level++;
        }
    }
}

int main()
{
    create();
    print_levelorder();
    root=mirror_tree(root);
    cout<<"\nMIRROR TREE\n";
    print_levelordermirror();
    return 0;
}
