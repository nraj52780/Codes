1. 
// O(nh) approach.. where h is the height


#include<bits/stdc++.h>
int maxmleft(BinaryTreeNode<int> *root)
{
    if(root==NULL) return INT_MIN;
    
    return max(root->data,max(maxmleft(root->left),maxmleft(root->right)));
}
int minmright(BinaryTreeNode<int> *root)
{
    if(root==NULL) return INT_MAX;
    
    return min(root->data,min(minmright(root->left),minmright(root->right)));
}
bool isBST(BinaryTreeNode<int> *root){
       /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
    if(root==NULL) return true;
    
    int maxm=maxmleft(root->left);
    int minm=minmright(root->right);
    
    bool res=root->data>=maxm&&root->data<=minm && isBST(root->left) && isBST(root->right);
    return res;
        

}
-------------------------------------------------------------------------------------------------
2nd approach
O(n)

#include<bits/stdc++.h>
class triplet
{
  public:
    bool res;
    int minm;
    int maxm;
};

triplet fun(BinaryTreeNode<int> *root)
{
     if(root==NULL) 
    {
        triplet obj;
        obj.res=true;
        obj.minm=INT_MAX;
        obj.maxm=INT_MIN;
        
        return obj;
    }
    
    triplet leftans=fun(root->left);
    triplet rightans=fun(root->right);
    
    int mx=max(root->data,max(leftans.maxm,rightans.maxm));
    int mn=min(root->data,min(leftans.minm,rightans.minm));
    bool res=root->data>=leftans.maxm&&root->data<=rightans.minm&&leftans.res&&rightans.res;
    triplet obj;
        obj.res=res;
        obj.minm=mn;
        obj.maxm=mx;
        
        return obj;
}
bool isBST(BinaryTreeNode<int> *root){
       /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
   triplet ans=fun(root);
    return ans.res;
  
        

}
