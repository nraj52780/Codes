
/***************
 * Following is the main function that er are using internally
 *
 
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
*******************/
#include<vector>
class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMax() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] > pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMax() {
        // Complete this function
        if(pq.size()==0) return 0;
        int ans=pq[0];
        int lidx=pq.size()-1;
        swap(pq[0],pq[lidx]);
        pq.pop_back();
        int parentidx=0;
        int leftchildidx=2*parentidx+1;
        int rightchildidx=2*parentidx+2;
        int maxidx;
        while(leftchildidx<pq.size())
        {
           maxidx=parentidx;
            if(pq[maxidx]<pq[leftchildidx])
            {
                maxidx=leftchildidx;
            }
            if(rightchildidx<pq.size() && pq[maxidx]<pq[rightchildidx])
            {
                maxidx=rightchildidx;
            }
            if(maxidx==parentidx) break;
            swap(pq[parentidx],pq[maxidx]);
            parentidx=maxidx;
            leftchildidx=2*parentidx+1;
            rightchildidx=2*parentidx+2;
        }
     return ans;   
    }
    
    
};
