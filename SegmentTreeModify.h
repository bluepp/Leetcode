/*
  2015-09-29
  bluepp
  May the force be with me!
  
  or a Maximum Segment Tree, which each node has an extra value max to store the maximum value in this node's interval.

Implement a modify function with three parameter root, index and value to change the node's value with [start, end] = [index, index] to the new given value. Make sure after this change, every node in segment tree still has the max attribute with the correct value.

Have you met this question in a real interview? Yes
Example
For segment tree:

                      [1, 4, max=3]
                    /                \
        [1, 2, max=2]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]
if call modify(root, 2, 4), we can get:

                      [1, 4, max=4]
                    /                \
        [1, 2, max=4]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=4], [3, 3, max=0], [4, 4, max=3]
or call modify(root, 4, 0), we can get:

                      [1, 4, max=2]
                    /                \
        [1, 2, max=2]                [3, 4, max=0]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=0]
Note
We suggest you finish problem Segment Tree Build and Segment Tree Query first.

Challenge
Do it in O(h) time, h is the height of the segment tree.
http://www.lintcode.com/en/problem/segment-tree-modify/#
*/


    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (!root || root->start > index || root->end < index) return;
        
        if (root->start == index && root->end == index)
        {
            root->max = value;
            return;
        }
        
        modify(root->left, index, value);
        modify(root->right, index, value);
        
        int left_max = root->left ? root->left->max : NULL;
        int right_max = root->right ? root->right->max : NULL;
        
        root->max = max(left_max, right_max);
    }
