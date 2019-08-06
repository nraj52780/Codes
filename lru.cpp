/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */
list<int>dq;
unordered_map<int,int>mp;
int cs;
LRUCache::LRUCache(int N)
{
     //Your code here
     dq.clear();
     mp.clear();
     cs=N;
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
     //Your code here
     unordered_map<int,int>::iterator it;
     it=mp.find(x);
     if(it==mp.end()) // if not present
     {
         if(dq.size()==cs)
         {
             int lst=dq.back();
             dq.pop_back();
             mp.erase(lst);
         }
     }
     else 
     {
         dq.remove(x);
         mp.erase(x);
     }
     dq.push_front(x);
     mp[x]=y;
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    //Your code here
    unordered_map<int,int>::iterator it;
    it=mp.find(x);
    if(it==mp.end())
    {
        return -1;
    }
    else
    {
        dq.remove(x);
        dq.push_front(x);
        return it->second;
    }
}
