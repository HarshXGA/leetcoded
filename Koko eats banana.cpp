class Solution {
public:
    bool alldone(vector<int>& piles,int limit, int h)
    {
        int k=0;
        for(auto i:piles)
        {
            k+= (i-1)/limit + 1;

            if(k>h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=*max_element(piles.begin(),piles.end()),mid;

        if(h==piles.size())
            return e;

        while(s<e)
        {
            mid = s+(e-s)/2;

            if(alldone(piles,mid,h))
            {
                e=mid;
            }
            else
                s=mid+1;
        }
      return s;
    }
};
