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
			cout<<Q.front()->data<<" "; 
			Q.pop(); // to pop the front element from the queue.
		}
	}
}
int main()
{
	bnode *root;
	root=NULL;
	int ele;
	cout<<"\nCONSTRUCTING A BINARY SEARCH TREE USING RECURSIVE FUNCTIONS.";
	cout<<"\nEnter the elements (-1 for exit):\n";
	while(1)
	{
		cout<<"Element:";
		cin>>ele;
		if(ele==-1) break;
		else
			root=insert(root,ele);
	}
	cout<<"\nTHE LEVEL ORDER TRAVERSAL OF YOUR TREE IS:";
	BFStree(root);
return 0;
}
