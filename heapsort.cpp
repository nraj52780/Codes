#include<bits/stdc++.h>
using namespace std;
void inplaceHeapSort(int pq[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * Taking input and printing output is handled automatically.
     */
    for(int i=1;i<n;i++)
    {
        int childidx=i;
        while(childidx>0)
        {
          int paridx=(childidx-1)/2;
            if(pq[childidx]<pq[paridx])
            {
                swap(pq[childidx],pq[paridx]);
             
            }
            else break;
            childidx=paridx;
        }
    }
 //   for(int i=0;i<n;i++) cout<<pq[i]<<" ";
   // cout<<endl;
    
    
    int sz=n;
    while(sz>1)
    {
        swap(pq[0],pq[sz-1]);
        sz--;
        int paridx=0;
        int leftchildidx=2*paridx+1;
        int rightchildidx=2*paridx+2;
        int minidx;
        while(leftchildidx<sz)
        {
            minidx=paridx;
            if(pq[minidx]>pq[leftchildidx])
            {
                minidx=leftchildidx;
            }
            if(rightchildidx<sz&&pq[minidx]>pq[rightchildidx])
            {
                minidx=rightchildidx;
            }
            
            if(minidx==paridx) break;
            swap(pq[minidx],pq[paridx]);
            paridx=minidx;
             leftchildidx=2*paridx+1;
             rightchildidx=2*paridx+2;
        }
    }

}
