#include <iostream>

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

node* createbst(node* root,int info){
    if(root==NULL){
        root=getnewnode(info); return root;}
        else if(info<=root->data)
            root->left=createbst(root->left,info);
        else
            root->right=createbst(root->right,info);
        return root;
}

node* createbsti(node* root,int info){
    node* t=root;
    node* par;
    if(t==NULL){
        t=getnewnode(info);
        return t;
    }
    while(t!=NULL){
        par=t;
        if(info<=t->data)
            t=t->left;
        else
            t=t->right;
    }
    t=getnewnode(info);
    if(info<=par->data)
        par->left=t;
    else
        par->right=t;
    return root;
}


node* findmin(node* root){
    if(root==NULL)
        return NULL;
        node* current=root;
        while(current->left!=NULL)
            current=current->left;
        return current;
}

/*
node* findminr(node* root){
    if(root==NULL)
        return NULL;
        else if(root->left==NULL)
        return root;
        else return findmin(root->left);
}
*/

node* findmax(node* root){
    if(root==NULL)
        return NULL;
    node* current=root;
    while(current->right)
        current=current->right;
    return current;
}

node* deletenode(node* root,int info){
    if(root==NULL)
        return NULL;
    else if(info<root->data)
        root->left=deletenode(root->left,info);
    else if(info>root->data)
        root->right=deletenode(root->right,info);
    else{
        if(root->left==NULL&&root->right==NULL){
            delete root;
            root=NULL;
                return root;
        }
        else if(root->left==NULL){
            node* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->right==NULL){
            node* temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else{
            node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
            return root;
        }
    }
}

void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* find(node* root, int info){
    if(root==NULL)
        return NULL;
    if(info<root->data)
        return find(root->left,info);
    if(info>root->data)
        return find(root->right,info);
    if(info==root->data)
        return root;
}

node* getsuccessor(node* root,int info){
    node* current=find(root,info);
    if(current==NULL)
        return NULL;
    if(current->right!=NULL)
        return findmin(current->right);
    else{
        node* successor=NULL;
            node* ancestor=root;
            while(ancestor!=current){
                if(current->data<ancestor->data){
                    successor=ancestor;
                    ancestor=ancestor->left;
                }
                else
                    ancestor=ancestor->right;
            }
            return successor;
    }
}

int main()
{
    cout<<"Enter number of nodes\n";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
            cout<<"Enter data\n";
    int info;
    cin>>info;
        root=createbst(root,info);}
    cout<<"\n1.Insert(recursion)2.Insert(iteration)3.Delete4.Min5.Max6.InorderSuccessor7.Inorder8.Exit\n";
    cin>>n;
    while(n<=8){
        switch(n){
            case 1:{
            cout<<"Enter data\n";
            int info;
            cin>>info;
            root=createbst(root,info);
            break;
            }
            case 2:{
            cout<<"Enter data\n";
            int info;
            cin>>info;
            root=createbsti(root,info);
            break;
            }
            case 3:{
            cout<<"Enter data\n";
            int info;
            cin>>info;
            root=deletenode(root,info);
            break;
            }
            case 4:{int min=(findmin(root))->data;
            cout<<min;
            break;}
            case 5:{int max=(findmax(root))->data;
            cout<<max;
            break;}
            case 6:{
                cout<<"Enter number\n";
                int info;
                cin>>info;
                cout<<(getsuccessor(root,info))->data;
            break;
            }
            case 7:{inorder(root);
            break;}
            case 8:return 0;
        }
        cout<<"\n1.Insert(recursion)2.Insert(iteration)3.Delete4.Min5.Max6.InorderSuccessor7.Inorder8.Exit\n";
    cin>>n;
    }
    return 0;
}
