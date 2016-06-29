/*
bluepp
2016-06-01
May the force be with me!
https://leetcode.com/problems/moving-average-from-data-stream/
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/


/* 2016-06-30 , update */
class MovingAverage {
private:
    queue<int> q;
    int size;
    double sum;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        
        if (q.size() >= size)
        {
            sum -= q.front();
            q.pop();
        }
        
        q.push(val);
        sum += val;
        
        return sum / q.size();
        
    }
};





class MovingAverage {
private:
    vector<int> vec;
    int _size;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size = size;
    }
    
    double next(int val) {
        vec.push_back(val);
        
        double ret = 0;
        if (vec.size() < _size)
        {
            double s = 0;
            for (int i = 0; i < vec.size(); i++)
            {
                s += vec[i];
            }
            
            ret = s/vec.size();
        }
        else
        {
            double s = 0;
            
            for (int i = vec.size()-_size; i < vec.size(); i++)
            {
                s += vec[i];
            }
            
            ret = s / _size;
        }
        
        return ret;
    }
};
