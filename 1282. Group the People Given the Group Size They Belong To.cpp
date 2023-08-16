class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& sizes) {
        vector<vector<int>> ans;
        int n=sizes.size();
        vector<int> group;
        //improves accuracy
        int maxi=*max_element(sizes.begin(),sizes.end());

        for(int i=1;i<=maxi;i++)
            for(int j=0;j<n;j++)
                if(sizes[j]==i)
                {
                    group.push_back(j);
                    if(group.size()==i)
                    {
                        ans.push_back(group);
                        group.clear();
                    }
                }

        return ans;
        
    }
};
