class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) {
        int n=str.length();
        int ans=-1;
        int tc=0,fc=0; //count of t and f
        int l=0,r=0; //left right


        //window of size mid is created.
        //now if minimum of tc or fc is <=k, then we can flip those and the window sized mid is a valid substring else not.
        if(str[r]=='F')
            ++fc;
        else
            ++tc;
            
        while(r<n)
        {
            if(min(fc,tc)<=k)
            {
                r++;
                
                if(r<n){
                if(str[r]=='F')
                    ++fc;
                else
                    ++tc;
                }
            }
            else
            {
                if(str[l]=='T')
                    --tc;
                else
                    --fc;
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};
