class Solution {
public:
    void solve(vector<int> &op, vector<vector<int>> &ans, vector<int> &arr,int tgt,int i=0)
        {
            if(i==arr.size() || tgt<0)
                return;

            if(tgt==0)
            {
                ans.push_back(op);
                return;
            }
            
            //include
            op.push_back(arr[i]);
            solve(op,ans,arr,tgt-arr[i],i);
            op.pop_back();
            //exclude
            solve(op,ans,arr,tgt,i+1);
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> op;
        vector<vector<int>> ans;

        solve(op,ans,candidates,target); 

        return ans;
    }
};
