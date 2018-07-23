/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int max_level = 0;
        int depth = 1; 
        vector <int> rightView;
        
        rightSideViewHelper(root, depth, max_level,rightView);
      //  rightView.insert(rightView.begin(),root->val);
                   
          return rightView;
    }
    
    
      void rightSideViewHelper(TreeNode * root,int depth, int & max_level, vector <int> & rightView){
        
       // static vector <int> rightView;
        
        if (root==NULL) return;
        
        if (depth>max_level){
            rightView.push_back(root->val);
            max_level = depth;
        }
        
        
        
        rightSideViewHelper(root->right,depth+1,max_level,rightView);
        rightSideViewHelper(root->left,depth+1,max_level,rightView);
        
        return ;
    }
};      

   