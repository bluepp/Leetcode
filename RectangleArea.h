/*
  2015-06-14
  bluepp
  May the force be with me!
  
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

https://leetcode.com/problems/rectangle-area/
*/

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int ret = (C-A)*(D-B) + (G-E)*(H-F);
        
        if (C < E || G < A || B > H || D < F)  return ret;
        
        int L = max(A, E);
        int LB = max(B, F);
        int R = min(C, G);
        int T = min(D, H);
        
        return ret - (R-L) * (T-LB);
    }
