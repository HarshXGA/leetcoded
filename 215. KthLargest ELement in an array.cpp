class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> heap;
        for(int i:nums)
        {
            heap.push(-i);
            if(heap.size()>k)
                heap.pop(); //popping the largest number 
        }
            
        return -heap.top(); //top is the largest number 
    }
};
