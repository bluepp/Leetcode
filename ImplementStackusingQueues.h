/*
  2015-06-13
  bluepp
  May the force be with me!
  
  Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

https://leetcode.com/problems/implement-stack-using-queues/

*/

/* my version */
class Stack {
private:
    queue<int> q1;
    queue<int> q2;
    
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        
        while (q1.size() > 1)
        {
            int k = q1.front();
            q1.pop();
            q2.push(k);
        }
        
        q1.pop();
        swap(q1, q2);
    }

    // Get the top element.
    int top() {
        
        int tmp;
        while (!q1.empty())
        {
            tmp = q1.front();
            q1.pop();
            q2.push(tmp);
        }
        
        swap(q1, q2);
        return tmp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};



class Stack {
private:
    queue<int> q1;
    queue<int> q2;
    void toQ1(queue<int>& q1, queue<int>& q2)
    {
        if (q1.empty())
        {
            q1 = q2;
            queue<int> q;
            q2 = q;
        }
    }
    
public:
    // Push element x onto stack.
    void push(int x) {
          toQ1(q1, q2);
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        toQ1(q1, q2);
        while (q1.size() > 0 && q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
    }

    // Get the top element.
    int top() {
         toQ1(q1, q2);
        while (q1.size() > 0 && q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int n = q1.front();
        q2.push(q1.front());
        q1.pop();

        return n;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
