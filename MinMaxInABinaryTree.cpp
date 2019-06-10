
1st approach

int findmax(BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return -1;
    
    int ans=root->data;
    
    int temp1,temp2;
    temp1=findmax(root->left);
    temp2=findmax(root->right);
    
    ans=max(temp2,max(temp1,ans));
            return ans;
    
}

int findmin(BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return INT_MAX;
    
    int ans=root->data;
    
    int temp1,temp2;
    temp1=findmin(root->left);
    temp2=findmin(root->right);
    
    ans=min(temp2,min(temp1,ans));
            return ans;
    
}

PairAns minMax(BinaryTreeNode<int> *root) {
    
      PairAns p;
      p.max=findmax(root);
      p.min=findmin(root);
      if(p.min==INT_MAX)
          p.min=-1;
    
      return p;
}



-------------------------------
2nd approach
class PairAns {
    public :
        int min;
        int max;
 };
PairAns minMax(BinaryTreeNode<int> *root) {
   
      PairAns p;
      p.max=INT_MIN;
      p.min=INT_MAX;
      if(root==NULL)
          return p;
      PairAns left=minMax(root->left);
      PairAns right=minMax(root->right);
      
       p.max=max(root->data,max(left.max,right.max));
       p.min=min(root->data,min(left.min,right.min));
    
      return p;
}
