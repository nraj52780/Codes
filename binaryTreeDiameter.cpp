O(nh) approach, where h is the height of tree.
for skew tree h=n;

int height(Node *root)
{
    if(root==NULL)
    return 0;
    
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node* root)
{
   // Your code here
   if(root==NULL)
   return 0;
   
   int op1=height(root->left)+height(root->right)+1;
   int op2=diameter(root->left);
   int op3=diameter(root->right);
   
   return max(op1,max(op2,op3));
}

-----------------------------------------------------
O(n) approach


#include<bits/stdc++.h>
using namespace std;
pair<int,int> heightdia(Node *root)
{
    if(root==NULL)
    {
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    
    pair<int,int> lchild=heightdia(root->left);
    pair<int,int> rchild=heightdia(root->right);
    
    int lh=lchild.first; 
    int rh=rchild.first;
    int ld=lchild.second; 
    int rd=rchild.second;
    
    int height=1+max(lh,rh);
    int dia= max(1+lh+rh,max(ld,rd));
    
    pair<int,int>p;
        p.first=height;
        p.second=dia;
        
        return p;
    
}
int diameter(Node* root)
{
   // Your code here
   if(root==NULL)
   return 0;
   
   pair<int,int>res=heightdia(root);
   return res.second;
}
