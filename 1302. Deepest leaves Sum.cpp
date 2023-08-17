/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int x=height(root->left);
        int y=height(root->right);


        return max(x,y)+1;
    }

    int sumofdeepestnodes(TreeNode* root,int &sum, int &maxheight,int height=1)
    {
        if(!root)
            return 0;
        
        if(height==maxheight)
        {
            sum+=root->val;
            return 0;
        }

        sumofdeepestnodes(root->left,sum,maxheight,height+1);
        sumofdeepestnodes(root->right,sum,maxheight,height+1);
        return 0;
    }
    int deepestLeavesSum(TreeNode* root) {
       int h=height(root); 
       int sum=0;
       sumofdeepestnodes(root,sum,h);
       return sum;
    }
};
