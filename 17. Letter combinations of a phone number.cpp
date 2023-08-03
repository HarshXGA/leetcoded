class Solution {
    vector<string> v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void solve(string &digits, vector<string> &ans,string &str, int idx=0)
    {
        //base case
        if(idx==digits.length())
          {
              ans.push_back(str);
              return ;
          }
        
        for(char i:v[digits[idx]-'2'])
        {
            str.push_back(i);
            solve(digits,ans,str,idx+1);
            str.pop_back(); //backtrack 
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
          return ans;
        string str="";
        solve(digits,ans,str);
        return ans;
    }
};
