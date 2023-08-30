class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";

        char ch;
        int i=0;
        while(1) //i is idx of string to check
        {
            if(i==strs[0].length())
                return ans;
            ch=strs[0][i];
            for(int j=0;j<n;j++) //to traverse the vectors length. i.e. all strings
            {
                if(i==strs[j].length() || strs[j][i]!=ch)
                    return ans;
                
            }
            ans+=ch;
            i++;
        }

        return ans;
    }
};
