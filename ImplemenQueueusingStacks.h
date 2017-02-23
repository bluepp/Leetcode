/*
  2015-07-07
  bluepp
  May the force be with me!
  
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

https://leetcode.com/problems/implement-queue-using-stacks/
*/

/* 2017-0-23 */
class MyQueue {
private:
    stack<int> s1, s2;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        while (s1.size() > 1)
        {
            int t = s1.top();
            s1.pop();
            s2.push(t);
        }
        
        int ret = s1.top();
        s1.pop();
        
        while (!s2.empty())
        {
            int t = s2.top();
            s2.pop();
            s1.push(t);
        }
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        
        int ret = 0;
        while (!s1.empty())
        {
            ret = s1.top();
            s1.pop();
            
            s2.push(ret);
        }
        
        while (!s2.empty())
        {
            int t = s2.top();
            s2.pop();
            s1.push(t);
        }
        
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        return s1.empty() && s2.empty();
        
    }
};



class Queue {
private:
    stack<int> s1, s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        
        peek();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        
        if (s2.empty())
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};
