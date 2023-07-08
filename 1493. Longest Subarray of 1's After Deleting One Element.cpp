class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int l=0,r=0;
       int n=nums.size();
       int ans=-1,idx=-1; //maximise ans and store idx of zero.

       while(r<n)
       {
            if(nums[r]==0)
            {
                if(idx==-1)
                    idx=r;
                else
                {
                    l=idx+1;
                    idx=r;
                }
            }
            r++;
            ans=max(ans,r-l);
       }

       return ans-1;
    }
};

************************************
class Solution {
public:
    bool valid(vector<int>& nums,int size)
    {
        //make first window
        int l=0,r=0;
        int count=0;
        while(r<=size)
        {
            if(nums[r]==0)
                count++;
            r++;
        }
        if(count<2)
            return true;
        while(r<nums.size())
        {
            if(nums[l]==0)
                --count;
            if(nums[r]==0)
                ++count;
            l++;
            r++;
            if(count<2)
                return true;
        }
        return false;
        //move this fixed sized window
    }
    int longestSubarray(vector<int>& nums) {
       int start=1,end=nums.size();
       int ans=0; //maximise ans and store idx of zero.
       int mid=start+(end-start)/2;

       while(start<end)
       {
            if(valid(nums,mid))
            {
                ans=max(ans,mid);
                start=mid+1;
            }
            else
                end=mid;
            
            mid=start+(end-start)/2;
       }
       return ans;
    }
};
