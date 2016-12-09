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


/* 2016-12-09, update */
class Vector2D {
private:
    vector<int> v;
    int idx = 0;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        
        for (int i = 0; i < vec2d.size(); i ++)
        {
            for (int j = 0; j < vec2d[i].size(); j++)
            {
                v.push_back(vec2d[i][j]);
            }
        }
    }

    int next() {
        
        return v[idx++];
    }

    bool hasNext() {
        
        return idx < v.size();
    }
};





/* 2016-06-30, update */
class Vector2D {
private:
    vector<int> v;
    int i;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        
        for (auto p : vec2d)
        {
            v.insert(v.end(), p.begin(), p.end());
        }
        
    }

    int next() {
        
        return v[i++];
    }

    bool hasNext() {
        
        return i < v.size();
    }
};



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
  //    hasNext();  /* delte, 2015-08-17 */
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
  
  
/* 2016-06-19, not sure ? */
class Vector2D {
private:
    vector<vector<int>> ::iterator i, iend;
    int j = 0;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iend = vec2d.end();
    }

    int next() {
        return (*i)[j++];
    }

    bool hasNext() {
        
        while (i != iend && j == (*i).size())
        {
            i++;
            j = 0;
        }
        
        return i != iend && j < (*i).size(); //!!!!!!
    }
};
