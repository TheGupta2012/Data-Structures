#include<iostream>
#include<queue>
using namespace std;
struct bnode
{
	int data;
	bnode *left,*right;
};

bnode * insert(bnode *root, int dat)
{
	if(root==NULL)
		{
			bnode *temp= new bnode;
			temp->data=dat;
			temp->left=temp->right=NULL;
			root=temp;
		}
	else
	{
		if(dat<=root->data)
			root->left=insert(root->left,dat);
			
		else
			root->right=insert(root->right,dat);
		
	}
	return root;
}
int findminR(bnode* root) // recursive solutions
{
	if(root==NULL)	
		return -1;
	else
	{
		if(root->left==NULL)
			return (root->data);
		else
			findminR(root->left);
	}
}
int findmin(bnode *root)  // iterative solutions
{
	if(root==NULL)
		return -1;
	else
	{
		bnode *temp;
		temp=root;
		while(temp->left!=NULL)
			temp=temp->left;
		return temp->data;
	}
}
int findmaxR(bnode *root) // recursive solutions
{
	if(root==NULL)
		return -1;
	else
	{
		if(root->right==NULL)	
			return root->data;
		else
			findmaxR(root->right);
	}
}
int findmax(bnode *root)  // iterative solutions
{
	if(root==NULL)
		return -1;
	else
	{
		bnode *temp;
		temp=root;
		while(temp->right!=NULL)
			temp=temp->right;
		return temp->data;
	}
	}
int height(bnode *root)
{
		if(root==NULL) 
			return (-1);  // it's -1 here as if a node has no children and then if we return 0 from both
					      // the right empty subtreee and left empty subtree then the height of a leaf
					      // node would become 1 (because we return max(left,right)+1 ) and that would be
					      // wrong hence we return -1 for the base case so that the height of a leaf node
						  // is returned as 0 ...
		else                                                                                      
		{	int left,right;
			left=height(root->left);
			right=height(root->right);
			return(max(left,right)+1);
		}
}
bool search(bnode *root, int data)
{
	if(root==NULL)
		return false;
	else
	{
		if(root->data==data)
			return true;
		else if(root->data>data)
		{
			return search(root->left,data);
		}
		else if(root->data<data)
		{
			return search(root->right,data);
		}
		else
		 	return false;
	}
}
void BFStree(bnode *root)
{
	if(root==NULL)
		cout<<"\nTree is empty";
	else
	{	queue<bnode*> Q; //stl queue inbuilt function. Making a queue of addresses.
		Q.push(root);
		while(!Q.empty())
		{
			bnode *current=Q.front(); // this just returns the address of the front element of the queue but 
			                          //  doesn't pop it from the queue.
			if(current->left!=NULL)
				Q.push(current->left);
			if(current->right!=NULL)
				Q.push(current->right);
			cout<<Q.front()->data<<":"; 
			Q.pop(); // to pop the front element from the queue.
		}
	}
}
vector <int> BFSv(bnode *root)
{       vector <int> v;
     	queue<bnode*> Q; //stl queue inbuilt function. Making a queue of addresses.
		Q.push(root);
		while(!Q.empty())
		{
			bnode *current=Q.front(); // this just returns the address of the front element of the queue but 
			                          //  doesn't pop it from the queue.
			if(current->left!=NULL)
				Q.push(current->left);
			if(current->right!=NULL)
				Q.push(current->right);
			v.push_back(Q.front()->data);
			Q.pop(); // to pop the front element from the queue.
		}
     return v;
	
}
//Depth first searches of trees...
//preoder traversal
void preorder(bnode *root)
{
	if(root==NULL)	return;
	else
	{
		cout<<root->data<<":";
		preorder(root->left);
		preorder(root->right);
	}
}
 void inorderV(bnode *root,vector<int> &v)
    {   if(root==NULL)
            return;
        else
        {	inorderV(root->left,v);
            v.push_back(root->data);
            inorderV(root->right,v);
        }
    }
void inorder(bnode *root)
{
	if(root==NULL)	return;
	else
	{
		inorder(root->left);
		cout<<root->data<<":";
		inorder(root->right);
	}
}
void postorder(bnode *root)
{
	if(root==NULL)	return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<":";
	}
}
bool islessSTmin(bnode *root,int val)
{
	if(root==NULL)	return true;
	else
	{
		if(findmax(root) < val)
			return true;
		else
			return false;
	}
}
bool isgreatSTmax(bnode *root, int val)
{
	if(root==NULL)	return true;
	else
	{
		if(findmin(root) > val)
			return true;
		else
		 	return false;
	}
}
bool islessST(bnode *root, int val)
{
	if(root==NULL)	return true;
	else
	{
		if(root->data <= val && islessST(root->left,val) && islessST(root->right,val))
			return true;
		else
			return false;
	}
}
bool isgreatST(bnode *root, int val)
{
	if(root==NULL) return true;
	else
	{
		if(root->data > val && isgreatST(root->left,val) && isgreatST(root->right,val))
			return true;
		else
			return false;
	}
}
bool TreeOrNot(bnode *root)
{
	if(root==NULL)
		return true;
	else
	{
		if(islessSTmin(root->left,root->data) && isgreatSTmax(root->right,root->data) && TreeOrNot(root->left) && TreeOrNot(root->right))
			return true;
		else
			return false;
		
	}
}
bool isBSTutil(bnode *root, int min, int max)
{
	if(root==NULL)
		return true;
	else
	{
		if(root->data > min && root->data < max && isBSTutil(root->left,min,root->data) && isBSTutil(root->right,root->data,max))
			return true;
		else
			return false;
	}
}
bool isBSTornot(bnode *root)
{
	return isBSTutil(root,INT_MIN,INT_MAX);
}
bnode *deleteNode(bnode* root, int data)
{
	if(root==NULL)
		return root;//root is NULL hence it is equivalent to returning NULL
	else if(root->data > data)
		root->left=deleteNode(root->left,data);
	else if(root->data < data)
		root->right=deleteNode(root->right,data);
	else
	{
		if(root->left == NULL && root->right == NULL)
			{	delete root;
				root=NULL;
				return root;
			}
		else if(root->right==NULL)
			{	// we can't just write delete root and then do root=root->left
				// as the connection to root->left would be lost when we delete
				// root. Hence, we store the address of root in a temp pointer 
				// and then we update root and delete the memory.
				bnode *temp=root;
				root=root->left;
				delete temp;
				return root;
			}
		else if(root->left==NULL)
			{
				bnode *temp=root;
				root=root->right;
				delete temp;
				return root;
			}
		else
		{	bnode *temp= new bnode;
			temp->data=findmin(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right, temp->data);
			return root;
		}
	}
}
bnode *FINDNODE(bnode *root, int dat)
{
	bnode *temp = root;
	if (temp->data==dat)
		return temp;
	else if(temp->data > dat)
		temp=temp->left;
	else if(temp->data < dat)
		temp=temp->right;
	else
	    return NULL;
}
int InorderS(bnode *root, int dat)
{
	if(root==NULL)
		return -1;
	else
	{
		if(!search(root,dat))
			return -1;
		else
		{	bnode *current=FINDNODE(root,dat);
			//case 1 -> there is an RST.
			if(current->right!=NULL)
				return (findmin(current->right));
			//case 2 -> there is no RST
			else
			{
				bnode *successor=NULL;
				bnode *ancestor=root;
				while(ancestor->data!=dat)
					{
						if(ancestor->data > dat)
							{
								successor=ancestor;
								ancestor=ancestor->left;
							}
						else
						{
							ancestor=ancestor->right;
						}
					}
				if(successor==NULL)
					return -1;
				else
					return (successor->data);			
			}
		}
	}
}













