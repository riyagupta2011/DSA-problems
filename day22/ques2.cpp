class MedianFinder {
public:
priority_queue<int,vector<int>,greater<int>> min_heap;
priority_queue<int> max_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty())
         max_heap.push(num);
        else if(max_heap.top() <num)
        min_heap.push(num);
        else
        max_heap.push(num);

        int size1=max_heap.size();
        int size2=min_heap.size();
        if(abs(size1-size2)==2)
        {
            if(size1>size2)
            {
                int x=max_heap.top();
                max_heap.pop();
                min_heap.push(x);
            }
            else
            {
                 int x=min_heap.top();
                min_heap.pop();
                max_heap.push(x);
            }
        }
       
    }
    
    double findMedian() {
        int size1=max_heap.size();
        int size2=min_heap.size();
        if((size1+size2)%2==0)
        {
            return (max_heap.top()+min_heap.top())/2.0;
        }
        if(size1>size2)
          return (double)max_heap.top();
        return (double)min_heap.top();
        
    }
};