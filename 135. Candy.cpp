class Solution {
public:
    std::vector<int> candies;
    int candy(vector<int>& child) {
        /*Find the minimum rating child, and give 1 candy to him.
        THREE CASES
        1. min rating child is in left extreme
            - so we need to move to the right and give candies to children one by one
        2. min rating child is in right extreme so we go in left dirn

        3. min rating child is in somewhere between so we split the array in two parts 
        and the problem is converted two cases mentioned above.
        */
        
        int n=child.size();
        candies=std::vector<int> (n,1);
       
       for(int i=1;i<n;i++)
       {
            if(child[i]>child[i-1])
                candies[i] = candies[i-1] + 1;
                
       }
        
        for(int i=n-2;i>=0;i--)
        {
            if(child[i]>child[i+1])
                candies[i]=std::max(candies[i],candies[i+1]+1);
        }

        return std::accumulate(candies.begin(),candies.end(),0);
    }
};
