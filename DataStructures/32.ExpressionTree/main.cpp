#include <iostream>
#include<stack>
#include<string.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		cout<<t->value<<" ";
		inorder(t->right);
	}
}

et* newNode(int v)
{
	et *temp = new et;
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
}

et* constructTree(char postfix[]){
    stack<et*>st;
    et *t,*t1,*t2;
    for(int i=0;i<strlen(postfix);i++){
        if(!isOperator(postfix[i])){
            t=newNode(postfix[i]);
            st.push(t);
        }
        else{
            t=newNode(postfix[i]);
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            t->right=t1;
            t->left=t2;
            st.push(t);
        }
    }
    t=st.top();
    st.pop();
    return t;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}
