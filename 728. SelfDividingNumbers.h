/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
*/

    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> ret;
        for (int i = left; i <= right; i++) {
            if (_isNumber(i)) {
                ret.push_back(i);
            }
        }
        
        return ret;
 
    }
    
    bool _isNumber(int n) {
        
        string str = to_string(n);
        
        for (auto p : str) {
            if (p == '0' || n % (p-'0')) {
                return false;
            }
        }
         
        return true;
       
    }


/* ---------------------------------------------------------- */

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        for (int i = left; i <= right; i++) {
            if (_isDivid(i)) {
                res.push_back(i);
            }
        }
        
        return res;
    }
    
    bool _isDivid(int n) {
        if (n < 10) {
            return true;
        }
        
        int nn = n;
        
        while (n) {
            int t = n % 10;
            if ((t == 0) || (nn % t)) {
                return false;
            } 
   
            n /= 10;
        }
        
        return true;
        
    }
