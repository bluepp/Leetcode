/*
  2015-06-15
  bluepp
  May the force be with me!
  
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

*/

class TwoSum {
private:
    unordered_map<int, int> map;

public:
    // Add the number to an internal data structure.
	void add(int number) {
	    map[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    
	    for (auto it : map)
	    {
	        int t = value - it.first;
	        
	        if ((t != it.first && map.count(t)) || (t == it.first && map[t] > 1)) return true;
	    }
	    
	    return false;
	}
	
};
