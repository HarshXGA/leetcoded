class Solution {
public:
    //we solve this using binary search bcz we need to find minimum of largest sum in sub array.
    //we can makea search space of minimum largest sum that we can have which is largest nums[i] and maximum largest sum is sum of all nums[i].
    //we choose values in search space and see if that largest sum is viable with the number of splits that we should have.
    // k is not more than 50
    //first we make the binary search template for the problem and then write the feasible function.
    bool feasible(vector<int>& nums,int limit,int k)
    {
        int sum=0;
        int partition=1;
        for(auto i:nums)
        {
            sum+=i;
            
            if(sum>limit)
            {
                sum=i;
                partition++;
            }
            if(partition>k)
                return false;
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        //step 1 : create sample space.
        int start=0,end=0;
        for(auto i:nums)
        {
            end+=i;
            start=max(start,i);
        }

        //now we have got our sample space and now we search into our sample space .
        int mid;

        while(start<end)
        {
            mid= start + (end-start)/2;

            //conditions check
            //if the mid is not feasible, then we need to increase mid
            //but if it is feasible, we would want to further minimise it.
            if(feasible(nums,mid,k))
            {
                end = mid;
            }
            else
            {
                start=mid+1;
            }
        }
        //now we make our feasible function
        return start;
    }
};
