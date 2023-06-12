class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<string> ans;
        
        while(i<n)
        {
            string str="";
            int count=0;
            str+=to_string(nums[i]);
            while(i<n-1 && nums[i]+1 == nums[i+1])
            {
                i++;
                count++;
            }
            if(count!=0)
            {
                str+="->";
                str+=to_string(nums[i]);
            }
            i++;
            ans.push_back(str);
        }
        return ans;
    }
};
