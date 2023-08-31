class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int l=haystack.length();
        int n=needle.length();

        if(l<n)
            return -1;
        
        if(l==n)
            return haystack==needle?0:-1;

        for(int i=0;i<=l-n;i++)
        {
            if(haystack[i]==needle[0])
            {
                string temp(haystack.begin()+i,haystack.begin()+i+n);
                cout<<"Temp : "<<temp<<endl;
                if(temp==needle)
                    return i;
            }
        }

        return -1;
    }
};
