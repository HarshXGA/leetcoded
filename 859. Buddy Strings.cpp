class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int first=-1,second=-1;
        vector<int> charcount(26,0);
        
        if(s.length()!=goal.length())
            return false;
        
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=goal[i])
            {
                if(first==-1)
                    first=i;
                else
                    second=i;  
            }

            charcount[goal[i]-'a']++;
        }

        if(first==-1 && second==-1)
        {
            for(int i=0;i<26;i++)
            {
                if(charcount[i]>1)
                    return true;
            }
            return false;
        }
        else if(first==-1 || second==-1)
            return false;
        else
            swap(s[first],s[second]);
        
        return s==goal;
    }
};
