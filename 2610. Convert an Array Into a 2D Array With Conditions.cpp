class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> count(n+1,0); //1-based indexing

        for(int i:nums)
            count[i]++;
        
        
        bool allclear;
        while(1)
        {
            allclear=true;
            nums.clear();
            for(int i=0;i<n+1;i++)
            {
                
                if(count[i]>0)
                {
                    nums.push_back(i);
                    count[i]--;
                    allclear=false;
                }
            }
            if(allclear)
                break;
            ans.push_back(nums);
        }
        
        return ans;
        
    }
};
