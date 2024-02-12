#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    unordered_map<string,int> mp;//for dublicate doesnt get create

    // bool isBalanced(string expression) {
    //     stack<char> s1;
    //     for (int i = 0; i<expression.size(); i++) {
    //         if (expression[i] == '(') {
    //             s1.push(expression[i]);
    //         } else if (expression[i] == ')') {
    //             if (s1.empty()) {
    //                 return false;
    //             }
    //             if (s1.top() == '(' && expression[i] == ')') {
    //                 s1.pop();
    //             }
    //         }
    //     }
    //     return s1.empty();
    // }
    int isBalanced(string s)// isko reveision karna hoga
    {
        stack<char> stck;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(')
                stck.push('(');
            else if(s[i] == ')')
            {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
            i++;
        }
        return stck.size();
    }

    void solve(string s, vector<string>& ans, int k) {
        // base case
        if(mp[s] != 0) 
            return;
        else
            mp[s]++; //mp[s] = 1

         if(k < 0){
            return;
        }
        if (k == 0) {
            if (!isBalanced(s)) {
                ans.push_back(s);
            }
            return;
        }
        

        // recursively try adding and skipping characters
        for (int i = 0; i < s.size(); i++) {
       
            solve(s.substr(0,i)+s.substr(i + 1), ans, k - 1);
          
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        string sub="";
        int k = 0;  // Initialize k to 0

          
        k=isBalanced(s);
        cout<<"kl "<<k<<endl;
       
        solve(s, ans, k);
        if(ans.size()==0){
        vector<string> output;
        string si="";
         output.push_back(si);
    return output;
        }
        return ans;
    }
}; 