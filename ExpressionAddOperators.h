/*
bluepp
2016-06-04
May the force be with me!

https://leetcode.com/problems/expression-add-operators/

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

   vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(num.size() == 0)  return result;
        help(result, "", num, target, 0, 0, 0);
        return result;
    }
    
    void help(vector<string>& result, string path, string num, int target, int pos, long cur, long prev) {
        
        if(pos == num.size()) {
            if(target == cur)  result.push_back(path);
            return;
        }

        for(int i = pos; i < num.size(); i++) {
            
            if(num[pos] == '0' && i > pos)  break;
            
            string sub_str = num.substr(pos, i - pos + 1);
            long sub_int = stol(sub_str);
            
            if(pos == 0) {
                help(result, path + sub_str, num, target, i + 1, sub_int, sub_int);
            }
            else {
                help(result, path + "+" + sub_str, num, target, i + 1, cur + sub_int, sub_int);
                help(result, path + "-" + sub_str, num, target, i + 1, cur - sub_int, -sub_int);
                help(result, path + "*" + sub_str, num, target, i + 1, cur - prev + prev * sub_int, prev * sub_int);
            }
        }
    }


