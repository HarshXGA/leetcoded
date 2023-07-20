class Solution {
public:
    void pusher(vector<int> & ans, stack<int> s)
    {
        if(s.empty())
            return;
        
        int x=s.top();
        s.pop();
        pusher(ans,s);
        ans.push_back(x);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        int x;
        

        for(int i=0;i<asteroids.size();i++)
        {   int A=asteroids[i];
            bool is_neutralized=false;
            if(A<0)
            {
                while(!s.empty())
                {
                    x=s.top();
                    if(x>-A)
                        break;
                    else if(x==-A)
                    {
                        s.pop();
                        is_neutralized=true;
                        break;
                    }
                    else
                    {
                        s.pop();
                        is_neutralized=false;
                    }
                }

                if(s.empty() && !is_neutralized)
                    ans.push_back(A);
            }
            else
            {
                s.push(A);
            }
        }

        pusher(ans,s);
        return ans;

    }
};
