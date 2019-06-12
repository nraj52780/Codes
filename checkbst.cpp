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
