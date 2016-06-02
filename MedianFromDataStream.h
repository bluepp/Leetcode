/*
bluepp
2016-06-02
May the force be with me!


https://leetcode.com/problems/find-median-from-data-stream/

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

/* https://leetcode.com/discuss/83525/recommend-beginners-implementation-detailed-explanation */
/*
The key idea is to use two priority_queue to store the small half and big half.

   the big half should store numbers reversely 

  always keep small.size()=large.size()  or  small.size()=large.size()+1
  */
  
  class MedianFinder {
private:
    priority_queue<long> small, large;
    
public:
   
    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        
       return small.size()>large.size() ? small.top() : (small.top()-large.top())/2.0;
        
    }
};


/* https://leetcode.com/discuss/99669/my-simple-c-solution-using-heap */
/*
share my easy code using two heaps and very easy to understand. 
MAXheap used to hold the half of less number,and minheap used to keep the other number. 
so ,according to the size of the two heaps .median ele
*/

class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    
public:
   
    // Adds a number into the data structure.
    void addNum(int num) {
        
        maxh.push(num);
        
        if (maxh.size() - minh.size() == 2)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        else if (minh.size() > 0)
        {
            maxh.push(minh.top());
            minh.pop();
            minh.push(maxh.top());
            maxh.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        
        if (maxh.size() == minh.size())
        {
            return (maxh.top()*1.0+minh.top()*1.0)/2;
        }
        else
        {
            return maxh.top();
        }
    }
};

