class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        
        int last=nums.back(); //get the biggest number we can have
        int n=nums.size();

        for(int i=n-2;i>=0;i--) //traverse from back
        {
            if(nums[i]<=last)
                last=nums[i]; //as largest element can now be this.
            else
            {
                int parts=nums[i]/last; 
                if(nums[i]%last==0)
                    ans=ans+parts-1;  //reduce parts by 1 
                else
                {
                    ans=ans+parts;   //divided the parts and the smallest number we will have is
                    //now nums[i+1]-1.
                    last=nums[i]/(parts+1);
                }

            }
        }
            
        return ans;
    }
};
