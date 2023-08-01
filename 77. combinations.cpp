class Solution {
public:
    void solve(vector<int> op, vector<vector<int>> &ans, int n,int k,int idx=1)
    {
        if(op.size()==k)
        {
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<=n;i++)
        {
            op.push_back(i);
            solve(op,ans,n,k,i+1);
            op.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> op;
        vector<vector<int>> ans;
        for(int i=1;i<=n-k+1;i++)
        {
            op.push_back(i);
            solve(op,ans,n,k,i+1);
            op.pop_back();
        }
        
        return ans;
    }
};
