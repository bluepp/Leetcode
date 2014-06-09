/*
	bluepp
	2014-06-09
	May the force be with me!
	
	Problem:    Gas Station

 	Source:     http://oj.leetcode.com/problems/gas-station/
 	Notes:
 	There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 	The solution is guaranteed to be unique.

 Solution: ...
*/

/* time limit exceed ? */
 int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int index, kgas = 0, kcost = 0;
        int n = gas.size();
        int left[n];
        for (int i = 0; i < n; i++)
            left[i] = 0;
        
        for (int i = 0; i < n; i++)
        {
            left[i] = gas[i] - cost[i];
            
            int index = i;
            if (left[i] < 0)
                continue;
                
            int k;    
            for (k = index+1; k < index+n; k++)
            {
                kgas += gas[k];
                kcost += cost[k];
            }
            
            if (k == index+n-1)
                return index;
        }
        
        return -1;
        
    }
    
    
    -----------------
    
     int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int sum = gas[0]-cost[0];
        int min = sum;
        int res = 0;
        
        for (int i = 1; i < n; i++)
        {
            sum += gas[i] - cost[i];
            
            if (sum < min)
            {
                min = sum;
                res = i;
            }
        }
        
        return sum >= 0 ? (res+1) % n : -1;
        
    }
