class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        int l=0,r=0;
        int ans=n+1;

        while(r<n)
        {
            sum+=nums[r];
            while(l<n && sum>=target)
            {
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }

       return ans==n+1 ?0:ans;
    }
};
