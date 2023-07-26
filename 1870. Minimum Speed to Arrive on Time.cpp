class Solution {
public:
    bool valid(vector<int>& dist, double hour,int speed)
    {
        double time=0;
        double temp;
        int n=dist.size();
        for(int i=0;i<n;i++)
        {
            temp=(double)dist[i]/speed;            
            if(i<n-1)
                time+=ceil(temp);
            else
                time+=temp;
            
            if(time>hour)
                return false;
        }
        return time<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=1;
        int e=10000000;
        int mid=s+(e-s)/2;
        int ans=10000001;
        while(s<=e)
        {
            if(valid(dist,hour,mid))
            {
                e=mid-1;
                ans=min(ans,mid);
            }
            else
            {
                s=mid+1;
            }
            mid = s +(e-s)/2;
        }

        return ans==10000001?-1:ans;
    }
};
