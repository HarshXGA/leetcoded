//using ARRAY
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;

        for(int i=1;i<=n;i++)
            v.push_back(i);
        
        int idx=0;
        while(v.size()>1)
        {
            idx=(idx+k-1)%v.size();
            v.erase(v.begin()+idx);
        }
        
        return v[0];
    }
};

// using QUEUES
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;

        for(int i=1;i<=n;i++)
            q.push(i);
        
        while(q.size()>1)
        {
            int temp=k;
            //push the elements to the back of the queue k-1 times
            while(temp>1)
            {
                int x=q.front();
                q.pop();
                q.push(x); // we are moving players back to the back of queue.
                temp--;
            }
            q.pop(); //eliminate the kth player from current 
        }
        return q.front(); //q.size()==1 and that is our winner.
    }
};
