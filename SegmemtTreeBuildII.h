/*
  2015-09-29
  bluepp
  May the force be with me!
  
The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.

start and end are both integers, they should be assigned in following rules:

The root's start and end is given by build method.
The left child of node A has start=A.left, end=(A.left + A.right) / 2.
The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
if start equals to end, there will be no children for this node.
Implement a build method with a given array, so that we can create a corresponding segment tree with every node
value represent the corresponding interval max value in the array, return the root of this segment tree.

Have you met this question in a real interview? Yes
Example
Given [3,2,1,4]. The segment tree will be:

                 [0,  3] (max = 4)
                  /            \
        [0,  1] (max = 3)     [2, 3]  (max = 4)
        /        \               /             \
[0, 0](max = 3)  [1, 1](max = 2)[2, 2](max = 1) [3, 3] (max = 4)

http://www.lintcode.com/en/problem/segmemt-tree-build-ii/#
*/

    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return _build(A, 0, A.size()-1);
    }
    
    SegmentTreeNode* _build(vector<int> &A, int start, int end)
    {
        if (start > end) return NULL;
        
        SegmentTreeNode *root = new SegmentTreeNode(start, end, INT_MAX);
        
        if (start == end)
        {
            root->max = A[start];
            return root;
        }
        
        root->left = _build(A, start, (start+end)/2);
        root->right = _build(A, (start+end)/2+1, end);
        
        int left_max = root->left ? root->left->max : INT_MAX;
        int right_max = root->right ? root->right->max : INT_MAX;
        
        root->max = max(left_max, right_max);
        return root;
    }
