//the problem
//Given the root of a binary search tree with distinct values, modify it so 
//that every node has a new value equal to the sum of the values of the original tree
 //that are greater than or equal to node.val.
 //link to the problem->
 // (https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)
//my solution
// i used level order and inorder traversal.
// removed the values less than a node's values from the total sum and updated that value.
vector <int> inorderV(TreeNode *root)
    {   vector <int> v,left,right;
        if(root==NULL)
            {v.push_back(-1);
            return v;}
        else
        {	left=inorderV(root->left);
            v.insert(v.end(),left.begin(),left.end());
            v.push_back(root->val);
            right=inorderV(root->right);
			v.insert(v.end(),right.begin(),right.end());
            return v;
        }
    }
class Solution {
public:
     
    TreeNode* bstToGst(TreeNode* root) {
        vector <int> inord = inorderV(root);
        auto it=inord.begin();
        while(it!=inord.end())
        {
            if(*it==-1)
            {
                it=inord.erase(it);
            }
            else
                ++it;
        }
        int sum = accumulate(inord.begin(),inord.end(),0);
     	queue<TreeNode*> Q; //stl queue inbuilt function. Making a queue of addresses.
		Q.push(root);
		while(!Q.empty())
		{
			TreeNode *current=Q.front(); // this just returns the address
            //of the front element of the queue but 
	        //  doesn't pop it from the queue.
			if(current->left!=NULL)
				Q.push(current->left);
			if(current->right!=NULL)
				Q.push(current->right);
			int ele=sum;
            for(int i=0;i<inord.size();i++)
            {
                if(inord[i]!=Q.front()->val)
                    ele-=inord[i];
                else
                    break;
            }
            Q.front()->val=ele;
			Q.pop(); // to pop the front element from the queue.
		}
     return root;
        
        
    }
};
// a very faad recursive solution to the problem.
class Solution {
public:
    void helper(TreeNode* root,int& val){
        if(root==NULL) return;
        helper(root->right,val);
        val+=root->val;
        root->val=val;
        helper(root->left,val);
        return;
    }    
    
    TreeNode* bstToGst(TreeNode* root) {
        int val=0;
        helper(root,val);
        return root;
    }
};
