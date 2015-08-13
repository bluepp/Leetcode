/* 
  2015-08-13
  bluepp
  May the force be with me!
  
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Show Hint 
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
https://leetcode.com/problems/flatten-2d-vector/
*/

/* key point, how to handle empty row ? */
/* https://leetcode.com/discuss/50259/20ms-c-solution-with-explanations */
class Vector2D {
private:
    vector<vector<int>> data;
    int row, col, r, c;
    void skipEmptyVector(void) {
        while (!col) {
            r++;
            col = data[r].size();
        }
    }
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        r = c = 0;
        row = vec2d.size();
        col = (row == 0 ? -1 : data[r].size());
        skipEmptyVector();
    }

    int next() {
        int elem = data[r][c];
        if (c == col - 1) {
            r++;
            c = 0;
            col = data[r].size();
        }
        else c++;
        skipEmptyVector();
        return elem;
    }

    bool hasNext() {
        return col != -1 && (r < row && c < col);
    }
};

/* using iterater, https://leetcode.com/discuss/50292/7-9-lines-added-java-and-c-o-1-space */
class Vector2D {
    vector<vector<int> >::iterator i, iend;
    int j = 0;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iend = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iend && j == (*i).size())
        {
            i++, j = 0;
        }
        
        return i != iend;
    }
};
  
  
