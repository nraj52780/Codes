#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class BinaryTree{

 public:
     int data;
     BinaryTree *left;
     BinaryTree *right;

     BinaryTree(ll data)
     {
         this->data=data;
         left=NULL;
         right=NULL;

     }
};
BinaryTree* recinput()
{
    int n;
    cout<<"enter any number"<<endl;
    cin>>n;
    if(n==-1)
        return NULL;

    BinaryTree* root=new BinaryTree(n);
    BinaryTree* leftchild=recinput();
    BinaryTree* rightchild=recinput();

    root->left=leftchild;
    root->right=rightchild;

    return root;

}
void recprint(BinaryTree* root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data<<",";
    }
    cout<<endl;
    recprint(root->left);
    recprint(root->right);
}
BinaryTree* levelinput()
{
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1)
        return NULL;
    BinaryTree *root=new BinaryTree(rootdata);
    queue<BinaryTree*>q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTree *top=q.front(); q.pop();
        cout<<"enter left child of root "<<top->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
             BinaryTree *leftchild=new BinaryTree(leftdata);
             top->left=leftchild;
             q.push(leftchild);
        }

        cout<<"enter right child of root "<<top->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
             BinaryTree *rightchild=new BinaryTree(rightdata);
             top->right=rightchild;
             q.push(rightchild);
        }


    }
    return root;
}

void levelprint(BinaryTree *root)
{
    if(root->data==-1)
        return;

    queue<BinaryTree*>q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTree *top=q.front(); q.pop();
        cout<<top->data<<":";
        if(top->left!=NULL)
        {
            BinaryTree *leftchild=top->left;
            cout<<"L:"<<leftchild->data<<",";
            q.push(leftchild);
        }
        else cout<<"L:"<<-1<<",";
         if(top->right!=NULL)
        {
            BinaryTree *rightchild=top->right;
            cout<<"R:"<<rightchild->data;
            q.push(rightchild);
        }
        else cout<<"R:"<<-1<<",";
        cout<<endl;

    }

}
int numnodes(BinaryTree *root)
{
    if(root==NULL)
        return 0;

    int ans=1;
    ans+=numnodes(root->left);
    ans+=numnodes(root->right);
    return ans;
}
int main()
{

  //BinaryTree *root=recinput();
  //recprint(root);
  BinaryTree *root1=levelinput();
  levelprint(root1);
  int cnt=numnodes(root1);
  cout<<cnt<<endl;


}
