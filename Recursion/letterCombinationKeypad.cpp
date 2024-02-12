#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void helper(string digits, int index, vector<string>& ans, string& sub, vector<string>& map) {
        if (index == digits.size()) {
            ans.push_back(sub);
            return;
        }
        
        int digit = digits[index] - '0';
        string keyvalue = map[digit];
        
        for (int i = 0; i < keyvalue.size(); i++) {
            sub.push_back(keyvalue[i]);
            helper(digits, index + 1, ans, sub, map);
            sub.pop_back();//jab last call ke baad uppar jaungaa ,toh jo bhi SUB me insert h ,use hata de ,nhi toh wo ,next data me nested ho jayega
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ans;
        if(digits.size()==0)
        return ans;
        string sub = "";
        helper(digits, 0, ans, sub, map);
        return ans;
    }
};